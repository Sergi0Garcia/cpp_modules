/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 09:36:41 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/06 11:29:01 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::valid_args(const int argc) {
  if (argc != 2) {
    std::cout << RED << "error: usage: <path>" << RESET << std::endl;
    return (false);
  }
  return (true);
}

bool BitcoinExchange::valid_file(const char *file_path) {
  if (static_cast<std::string>(file_path).empty())
    return (false);
  FILE *file = std::fopen(file_path, "r");
  if (file == NULL)
    return (false);
  std::fclose(file);
  return (true);
}

bool BitcoinExchange::parse_input(const char *file_path) {
  if (static_cast<std::string>(file_path).empty())
    return (false);
  FILE *file = std::fopen(file_path, "r");
  if (file == NULL)
    return (false);
  std::fclose(file);
  std::ifstream infile(file_path);
  std::string temp;
  int i = 0;
  while (std::getline(infile, temp)) {
    if (i == 0 && temp != "date | value") {
      std::cout << "Error: wrong headers" << std::endl;
      return (false);
    };
  };
  return (true);
}

int countRepetitions(const std::string &str, char target) {
  int count = 0;

  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == target)
      count++;
  };
  return (count);
}

bool validateDate(const std::string &date) {
  std::regex pattern("^\\d{4}-\\d{2}-\\d{2}$");
  return std::regex_match(date, pattern);
}

bool validateValue(const std::string &number) {
  std::regex pattern("^\\d+(\\.\\d+)?|\\.\\d+$");
  return std::regex_match(number, pattern);
}

bool BitcoinExchange::parse_db(const char *file_path) {
  std::ifstream infile(file_path);
  std::string temp;

  int i = 0;
  while (std::getline(infile, temp)) {
    if (i == 0 && temp != "date,exchange_rate") {
      std::cout << "Wrong header config file in db" << std::endl;
      return (false);
    }
    if (i > 0) {
      if (countRepetitions(temp, ',') != 1) {
        std::cout << "temp" << temp << std::endl;
        std::cout << "Should have 1 comma" << std::endl;
        return (false);
      }
      std::size_t pos = temp.find(',');
      if (pos != std::string::npos) {
        std::string date = temp.substr(0, pos);
        std::string value = temp.substr(pos + 1);
        if (!validateDate(date)) {
          std::cout << "Wrong date format: " << date << std::endl;
          return (false);
        }
        if (!validateValue(value)) {
          std::cout << "Wrong value format: " << value << std::endl;
          return (false);
        }
        double value_double = std::stod(value);
        _data[date] = value_double;
      } else {
        std::cout << "Delimeter , not found" << std::endl;
        return (false);
      }
    }
    i++;
  };
  return (true);
}

bool BitcoinExchange::print_value(const std::string date) {
  std::cout << std::fixed << std::setprecision(2) << _data[date] << std::endl;
  return (true);
}