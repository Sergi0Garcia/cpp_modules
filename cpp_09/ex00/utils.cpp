/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:15:24 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/19 13:15:40 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "Colors.hpp"
#include "Errors.hpp"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

bool print_error(ERROR err) {
  std::cout << RED << "Error: ";
  switch (err) {
  case ERROR_ARGC:
    std::cout << "usage: <path>";
    break;
  case DB_FILE:
    std::cout << "DB error: no file found";
    break;
  case DB_EMPTY_FILE:
    std::cout << "DB error: empty file";
    break;
  case DB_READ_ACCESS:
    std::cout << "DB error: cannot open file";
    break;
  case DB_WRONG_HEADERS:
    std::cout << "DB error: wrong headers";
    break;
  case DB_COMMA_SEPARATOR:
    std::cout << "DB error: should contain 1 comma separator";
    break;
  case DB_DATE_FORMAT:
    std::cout << "DB error: must be valid date format YYYY-MM-DD";
    break;
  case DB_PRICE_VALUE:
    std::cout << "DB error: price value should be positive number";
    break;
  case DB_DELIMETER_NOT_FOUND:
    std::cout << "DB error: delimeter (,) not found";
    break;
  case INPUT_NOT_FOUND:
    std::cout << "input error: no file found";
    break;
  case INPUT_EMPTY_FILE:
    std::cout << "input error: empty file";
    break;
  case INPUT_READ_ACCESS:
    std::cout << "input error: cannot open file";
    break;
  case INPUT_WRONG_HEADERS:
    std::cout << "input error: wrong headers";
    break;
  case INPUT_VALUE_TOO_BIG:
    std::cout << "input error: too large number";
    break;
  case INPUT_NEGATIVE_NUMBER:
    std::cout << "input error: not a positive number";
    break;
  case INPUT_DATE_FORMAT:
    std::cout << "input error: must be valid date format YYYY-MM-DD";
    break;
  case OP_DB_VALUE:
    std::cout << "operation error: DB value is negative";
    break;
  case UNKNOWN_ERROR:
    std::cout << "operation error: DB value is negative";
    break;
  default:
    std::cout << "unknown error";
    break;
  }
  std::cout << RESET << std::endl;
  // Always returning false
  return (false);
}

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

int custom_stoi(const std::string &str) {
  int result = 0;
  bool negative = false;
  std::size_t i = 0;

  if (str[i] == '-') {
    negative = true;
    ++i;
  }
  for (; i < str.length(); ++i) {
    if (isdigit(str[i])) {
      result = result * 10 + (str[i] - '0');
    } else {
      print_error(UNKNOWN_ERROR);
      return (-1);
    }
  }

  return negative ? -result : result;
}

double customStod(const std::string &str) {
  std::istringstream iss(str);
  double number;

  if (!(iss >> number)) {
    print_error(UNKNOWN_ERROR);
    exit(1);
  }
  return number;
}

std::string trimWhitespace(const std::string &word) {
  size_t start = word.find_first_not_of(" \t\n\r");
  size_t end = word.find_last_not_of(" \t\n\r");
  if (start == std::string::npos) {
    return "";
  }
  return word.substr(start, end - start + 1);
}

bool isLeapYear(int year) {
  if (year % 400 == 0)
    return true;
  else if (year % 100 == 0)
    return false;
  else if (year % 4 == 0)
    return true;
  return false;
}

bool validateDate(std::string str) {
  if (str.length() < 10)
    return (false);
  if (!std::isdigit(str[0]) || !std::isdigit(str[1]) || !std::isdigit(str[2]) ||
      !std::isdigit(str[3]) || !std::isdigit(str[5]) || !std::isdigit(str[6]) ||
      !std::isdigit(str[8]) || !std::isdigit(str[9]) || str[4] != '-' ||
      str[7] != '-')
    return (false);
  if ((str[8] == '0' && str[9] == '0') || (str[5] == '0' && str[6] == '0') ||
      (str[0] == '0' && str[1] == '0' && str[2] == '0' && str[3] == '0'))
    return (false);
  int year = getYear(str);
  int month = getMonth(str);
  int day = getDay(str);
  if (day > 31)
    return (false);
  if (month == 0 || month > 12)
    return (false);
  if ((month == 4 || month == 6 || month == 9 || month == 11) && (day >= 31))
    return (false);
  if (month == 2 && isLeapYear(year) && day > 29)
    return (false);
  if (month == 2 && !isLeapYear(year) && day > 28)
    return (false);
  return (true);
}

bool validateValue(std::string str) {
  std::string trimmed_str = trimWhitespace(str);
  if (trimmed_str.find('-') != std::string::npos)
    return (false);
  for (size_t i = 0; i < trimmed_str.length(); i++) {
    if (!(isdigit(trimmed_str[i]) || str[i] == '.'))
      return (false);
  }
  return (true);
}

int getYear(std::string str) {
  int year = -1;
  std::size_t pos = str.find('-');
  year = custom_stoi(str.substr(0, pos));
  return (year);
}

int getMonth(std::string str) {
  int month = -1;
  std::string sub;
  std::size_t pos1 = str.find('-');
  sub = str.substr(pos1 + 1, 2);
  month = custom_stoi(sub);
  return (month);
}

int getDay(std::string str) {
  int day = -1;
  std::size_t pos1 = str.find('-');
  std::size_t pos2 = str.find('-', pos1 + 1);
  std::string sub = str.substr(pos2 + 1);
  day = custom_stoi(sub);
  return (day);
}

std::string getPreviousDay(int year, int month, int day) {
  std::string date;
  if (day == 1) {
    std::stringstream sm;
    std::stringstream sd;
    if (month == 1) {
      std::string m = to_string(12);
      std::string d = to_string(31);
      sm << std::setfill('0') << std::setw(2) << m;
      sd << std::setfill('0') << std::setw(2) << d;
      date = to_string(year - 1) + '-' + sm.str() + '-' + sd.str();
      return (date);
    } else {
      std::string m = to_string(month - 1);
      std::string d = to_string(31);
      sm << std::setfill('0') << std::setw(2) << m;
      sd << std::setfill('0') << std::setw(2) << d;
      date = to_string(year) + '-' + sm.str() + '-' + sd.str();
      return (date);
    }
  } else {
    std::string m = to_string(month);
    std::string d = to_string(day - 1);
    std::stringstream sm;
    std::stringstream sd;
    sm << std::setfill('0') << std::setw(2) << m;
    sd << std::setfill('0') << std::setw(2) << d;
    date = to_string(year) + '-' + sm.str() + '-' + sd.str();
    return (date);
  }
  return (date);
}
