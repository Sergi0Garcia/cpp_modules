/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:11:34 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/10 12:43:05 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Colors.hpp"
#include <cctype>
#include <cstdlib>
#include <string>

ScalarConverter::ScalarConverter(const std::string &input) : _input(input) {
  std::cout << GREEN;
  std::cout << "[ScalarConverter] constructor called" << std::endl;
  std::cout << RESET;
  this->convert();
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[ScalarConverter] copy constructor called" << std::endl;
  std::cout << RESET;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  if (this != &other) {
    this->_input = other._input;
    this->_char = other._char;
    this->_int = other._int;
    this->_float = other._float;
    this->_double = other._double;
  }
  return (*this);
}

ScalarConverter::~ScalarConverter() {
  std::cout << RED;
  std::cout << "[ScalarConverter] destructor called" << std::endl;
  std::cout << RESET;
}

bool ScalarConverter::is_char(void) const {
  if (_input.length() != 1)
    return (false);
  if (!std::isprint(_input[0]))
    return (false);
  if (!std::isalpha(_input[0]))
    return (false);
  return (true);
}

bool ScalarConverter::is_int(void) const {
  int i = 0;
  long value;

  if (_input.empty())
    return (false);
  if (_input[i] == '+' || _input[i] == '-')
    i = 1;
  while (_input[i]) {
    if (!std::isdigit(_input[i]))
      return (false);
    i++;
  }
  value = strtol(_input.c_str(), NULL, 10);
  if (value > std::numeric_limits<int>::max() ||
      value < std::numeric_limits<int>::min())
    return (false);
  return (true);
}

bool ScalarConverter::is_float(void) const {
  int i = 0;
  double value;

  if (_input.empty())
    return (false);
  if (_input[0] == '.')
    return (false);
  if (_input[0] == '+' || _input[0] == '-')
    i = 1;
  if (i == 1 && !std::isdigit(_input[i]))
    return (false);
  int val = _input.find('.');
  if (val == -1)
    return (false);
  if (!std::isdigit(_input[val + 1]))
    return (false);
  if (_input[static_cast<int>(_input.length() - 1)] != 'f')
    return (false);
  while (_input[i] && i < static_cast<int>(_input.length() - 1)) {
    if (!std::isdigit(_input[i]) && i != val)
      return (false);
    i++;
  }
  value = strtod(_input.c_str(), NULL);
  if (value > std::numeric_limits<float>::max() ||
      value < -std::numeric_limits<float>::max())
    return (false);
  return (true);
}

bool ScalarConverter::is_double(void) const {
  int i = 0;
  long double value;

  if (_input.empty())
    return (false);
  if (_input[0] == '.')
    return (false);
  if (_input[0] == '+' || _input[0] == '-')
    i = 1;
  if (i == 1 && !std::isdigit(_input[i]))
    return (false);
  int val = _input.find('.');
  if (val == -1)
    return (false);
  if (!std::isdigit(_input[val + 1]))
    return (false);
  while (_input[i] && i < static_cast<int>(_input.length())) {
    if (!std::isdigit(_input[i]) && i != val)
      return (false);
    i++;
  }
  value = strtold(_input.c_str(), NULL);
  if (value > std::numeric_limits<double>::max() ||
      value < -std::numeric_limits<double>::max())
    return (false);
  return (true);
}

void ScalarConverter::convert(void) {
  std::cout << "[ScalarConverter] converting ... " << std::endl;
  std::cout << "[ScalarConverter] is_char: " << is_char() << std::endl;
  std::cout << "[ScalarConverter] is_int: " << is_int() << std::endl;
  std::cout << "[ScalarConverter] is_float: " << is_float() << std::endl;
  std::cout << "[ScalarConverter] is_double: " << is_double() << std::endl;
}