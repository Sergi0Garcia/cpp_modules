/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 09:36:41 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/07 12:59:11 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

// --------------- utility functions ------------------
bool is_empty_file(std::ifstream &pFile) {
  return pFile.peek() == std::ifstream::traits_type::eof();
}

int countRepetitions(const std::string &str, char target) {
  int count = 0;
  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == target)
      count++;
  };
  return (count);
}

std::string trimWhitespace(const std::string &word) {
  size_t start = word.find_first_not_of(" \t\n\r");
  size_t end = word.find_last_not_of(" \t\n\r");
  if (start == std::string::npos) {
    return "";
  }
  return word.substr(start, end - start + 1);
}

bool validateDate(std::string str) {
  if (str.length() < 10)
    return (false);
  if (!std::isdigit(str[0]) || !std::isdigit(str[1]) || !std::isdigit(str[2]) ||
      !std::isdigit(str[3]) || !std::isdigit(str[5]) || !std::isdigit(str[6]) ||
      !std::isdigit(str[8]) || !std::isdigit(str[9]) || str[4] != '-' ||
      str[7] != '-')
    return (false);
  return (true);
}

bool validateValue(std::string str) {
  if (str.find('-') != std::string::npos)
    return (false);
  for (size_t i = 0; i < str.length(); i++) {
    if (!(isdigit(str[i]) || str[i] == '.'))
      return (false);
  }
  return (true);
}

// --------------- utility functions ------------------

bool BitcoinExchange::valid_database() {
  std::ifstream infile(DB_CSV_PATH);
  if (!infile) {
    std::cout << RED << "DB error: no file found" << RESET << std::endl;
    return (false);
  }
  if (is_empty_file(infile)) {
    std::cout << RED << "DB error: empty file" << RESET << std::endl;
    return (false);
  }
  FILE *file = std::fopen(DB_CSV_PATH, "r");
  if (file == NULL) {
    std::cout << RED << "DB error: cannot open file" << RESET << std::endl;
    return (false);
  }
  std::fclose(file);
  infile.close();
  return (true);
}

bool BitcoinExchange::parse_database(void) {
  std::ifstream infile(DB_CSV_PATH);
  std::string temp;

  int i = 0;
  while (std::getline(infile, temp)) {
    if (i == 0 && temp != "date,exchange_rate") {
      std::cout << RED << "Wrong headers config" << RESET << std::endl;
      return (false);
    }
    if (i > 0) {
      if (countRepetitions(temp, ',') != 1) {
        std::cout << RED << "Should contain 1 comma" << RESET << std::endl;
        return (false);
      }
      std::size_t pos = temp.find(',');
      if (pos != std::string::npos) {
        std::string date = temp.substr(0, pos);
        std::string value = temp.substr(pos + 1);
        if (!validateDate(date)) {
          std::cout << RED << "Wrong format: " << date << RESET << std::endl;
          return (false);
        }
        if (!validateValue(value)) {
          std::cout << RED << "Wrong format: " << value << RESET << std::endl;
          return (false);
        }
        double value_double = std::stod(value);
        _data[date] = value_double;
      } else {
        std::cout << RED << "Delimeter (,) not found" << std::endl;
        return (false);
      }
    }
    i++;
  };
  infile.close();
  return (true);
}

bool BitcoinExchange::valid_arguments(const int argc) {
  if (argc != 2) {
    std::cout << RED << "error: usage: <path>" << RESET << std::endl;
    return (false);
  }
  return (true);
}

bool BitcoinExchange::valid_input_file(const char *file_path) {
  std::ifstream infile(file_path);
  if (!infile) {
    std::cout << RED << "input error: no file found" << RESET << std::endl;
    return (false);
  }
  if (is_empty_file(infile)) {
    std::cout << RED << "input error: empty file" << RESET << std::endl;
    return (false);
  }
  FILE *file = std::fopen(file_path, "r");
  if (file == NULL) {
    std::cout << RED << "input error: cannot open file" << RESET << std::endl;
    return (false);
  }
  std::fclose(file);
  std::string temp;
  std::getline(infile, temp);
  if (temp != "date | value") {
    std::cout << RED << "error wrong input headers" << RESET << std::endl;
    return (false);
  }
  infile.close();
  return (true);
}

bool BitcoinExchange::execute(const char *file_path) {
  std::ifstream infile(file_path);
  std::string temp;
  std::getline(infile, temp);

  int i = 0;
  while (std::getline(infile, temp)) {
    if (countRepetitions(temp, '|') != 1)
      std::cout << RED << "Error: bad input => " << temp << RESET << std::endl;
    std::size_t pos = temp.find('|');
    if (pos != std::string::npos) {
      std::string date = temp.substr(0, pos);
      std::string value = temp.substr(pos + 1);
      date = trimWhitespace(date);
      value = trimWhitespace(value);
      if (!validateDate(date)) {
        std::cout << RED << "Error: wrong date format: " << date << RESET
                  << std::endl;
      }
      if (!validateValue(value)) {
        std::cout << RED << "Error: not a positive number " << value << RESET
                  << std::endl;
      }
      if (!_data[date]) {
        std::cout << "Missing logic for finding smaller date" << std::endl;
      } else {
        double value_double = std::stod(value);
        std::cout << date << " => " << value << " = " << std::fixed
                  << std::setprecision(2) << _data[date] * value_double
                  << std::endl;
      }
    } else {
      std::cout << RED << "Error: bad input => " << temp << RESET << std::endl;
    }
    i++;
  };
  infile.close();
  return (true);
}