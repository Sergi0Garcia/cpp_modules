/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 09:36:41 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/11 12:50:02 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

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

int getYear(std::string str) {
  int year = -1;
  std::size_t pos = str.find('-');
  year = std::stoi(str.substr(0, pos));
  return (year);
}

int getMonth(std::string str) {
  int month = -1;
  std::size_t pos1 = str.find('-');
  std::size_t pos2 = str.find('-', pos1 + 1);
  month = std::stoi(str.substr(pos1 + 1, pos2));
  return (month);
}

std::string getPreviousDay(int year, int month, int day) {
  std::string date;
  if (day == 1) {
    std::stringstream sm;
    std::stringstream sd;
    if (month == 1) {
      std::string m = std::to_string(12);
      std::string d = std::to_string(31);
      sm << std::setfill('0') << std::setw(2) << m;
      sd << std::setfill('0') << std::setw(2) << d;
      date = std::to_string(year - 1) + '-' + sm.str() + '-' + sd.str();
      return (date);
    } else {
      std::string m = std::to_string(month - 1);
      std::string d = std::to_string(31);
      sm << std::setfill('0') << std::setw(2) << m;
      sd << std::setfill('0') << std::setw(2) << d;
      date = std::to_string(year) + '-' + sm.str() + '-' + sd.str();
      return (date);
    }
  } else {
    std::string m = std::to_string(month);
    std::string d = std::to_string(day - 1);
    std::stringstream sm;
    std::stringstream sd;
    sm << std::setfill('0') << std::setw(2) << m;
    sd << std::setfill('0') << std::setw(2) << d;
    date = std::to_string(year) + '-' + sm.str() + '-' + sd.str();
    return (date);
  }
  return (date);
}

int getDay(std::string str) {
  int day = -1;
  std::size_t pos1 = str.find('-');
  std::size_t pos2 = str.find('-', pos1 + 1);
  day = std::stoi(str.substr(pos2 + 1, str.length()));
  return (day);
}

double BitcoinExchange::getDBValue(std::string date) {
  std::map<std::string, double> data = _data;
  std::string c_date = date;
  if (data.find(c_date) != data.end() && data[c_date] >= 0) {
    return (data[c_date]);
  }
  while (!data[c_date] && getYear(c_date) > 2008) {
    c_date = getPreviousDay(getYear(c_date), getMonth(c_date), getDay(c_date));
    if (data.find(c_date) != data.end() && data[c_date] >= 0)
      return (data[c_date]);
  }
  return (-1);
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
    if (countRepetitions(temp, '|') != 1) {
      std::cout << RED << "Error: bad input => " << temp << RESET << std::endl;
      continue;
    }
    std::size_t pos = temp.find('|');
    if (pos != std::string::npos) {
      std::string date = temp.substr(0, pos);
      std::string value = temp.substr(pos + 1);
      date = trimWhitespace(date);
      value = trimWhitespace(value);
      if (!validateDate(date)) {
        std::cout << RED << "Error: wrong date format: " << date << RESET
                  << std::endl;
        continue;
      }
      if (!validateValue(value)) {
        std::cout << RED << "Error: not a positive number " << RESET
                  << std::endl;
        continue;
      }
      double valDB = this->getDBValue(date);
      double value_double = std::stod(value);
      if (value_double > 1000) {
        std::cout << RED << "Error: too large number " << RESET << std::endl;
        continue;
      }
      if (valDB >= 0) {
        std::cout << date << " => " << value << " = " << std::fixed
                  << std::setprecision(2) << valDB * value_double << std::endl;
      } else {
        std::cout << RED << "Error reading DB value " << value << RESET
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

bool BitcoinExchange::print_value(const std::string date) {
  std::cout << "DB value: " << this->getDBValue(date) << std::endl;
  return (false);
}