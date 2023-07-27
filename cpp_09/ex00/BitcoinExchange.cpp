/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 09:36:41 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/27 11:19:09 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Errors.hpp"
#include "Utils.hpp"
#include <sys/unistd.h>
#include <unistd.h>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this == &other)
    return (*this);
  this->_data = other._data;
  return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

double BitcoinExchange::getDBValue(std::string date) {
  std::map<std::string, double> data = _data;
  std::string c_date = date;
  if (data.find(c_date) != data.end() && data[c_date] >= 0) {
    return (data[c_date]);
  }
  while (!data[c_date] && getYear(c_date) > 2008) {
    if (getYear(c_date) > 2023)
      c_date =
          getPreviousDay(getYear("2023"), getMonth(c_date), getDay(c_date));
    c_date = getPreviousDay(getYear(c_date), getMonth(c_date), getDay(c_date));
    if (data.find(c_date) != data.end() && data[c_date] >= 0)
      return (data[c_date]);
  }
  return (-1);
}

bool BitcoinExchange::valid_arguments(const int argc) {
  if (argc != 2)
    return (print_error(ERROR_ARGC));
  return (true);
}

bool BitcoinExchange::valid_database() {
  std::ifstream infile(DB_CSV_PATH);
  if (access(DB_CSV_PATH, F_OK) != 0)
    return (print_error(DB_FILE));
  FILE *file = std::fopen(DB_CSV_PATH, "r");
  if (file == NULL)
    return (print_error(DB_READ_ACCESS));
  std::fclose(file);
  if (is_empty_file(infile))
    return (print_error(DB_EMPTY_FILE));
  infile.close();
  return (true);
}

bool BitcoinExchange::valid_input_file(const char *file_path) {
  std::ifstream infile(file_path);
  if (access(file_path, F_OK) != 0)
    return (print_error(INPUT_NOT_FOUND));
  FILE *file = std::fopen(file_path, "r");
  if (file == NULL)
    return (print_error(INPUT_READ_ACCESS));
  std::fclose(file);
  if (is_empty_file(infile))
    return (print_error(INPUT_EMPTY_FILE));
  std::string temp;
  std::getline(infile, temp);
  if (temp != "date | value")
    return (print_error(INPUT_WRONG_HEADERS));
  infile.close();
  return (true);
}

bool BitcoinExchange::parse_database(void) {
  std::ifstream infile(DB_CSV_PATH);
  std::string temp;

  int i = 0;
  while (std::getline(infile, temp)) {
    if (i == 0 && temp != "date,exchange_rate")
      return (print_error(DB_WRONG_HEADERS));
    if (i > 0) {
      if (countRepetitions(temp, ',') != 1)
        return (print_error(DB_COMMA_SEPARATOR));
      std::size_t pos = temp.find(',');
      if (pos != std::string::npos) {
        std::string date = temp.substr(0, pos);
        std::string value = temp.substr(pos + 1);
        if (!validateDate(date))
          return (print_error(DB_DATE_FORMAT));
        if (!validateValue(value))
          return (print_error(DB_PRICE_VALUE));
        double value_double = customStod(value);
        _data[date] = value_double;
      } else {
        return (print_error(DB_DELIMETER_NOT_FOUND));
      }
    }
    i++;
  };
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
        print_error(INPUT_DATE_FORMAT);
        continue;
      }
      if (!validateValue(value)) {
        print_error(INPUT_NEGATIVE_NUMBER);
        continue;
      }
      double valDB = this->getDBValue(date);
      double value_double = customStod(value);
      if (value_double > 1000) {
        print_error(INPUT_VALUE_TOO_BIG);
        continue;
      }
      if (valDB >= 0) {
        std::cout << date << " => " << value << " = " << std::fixed
                  << std::setprecision(2) << valDB * value_double << std::endl;
      } else {
        print_error(OP_DB_VALUE);
      }
    } else {
      std::cout << RED << "Error: bad input => " << temp << RESET << std::endl;
    }
    i++;
  };
  infile.close();
  return (true);
}