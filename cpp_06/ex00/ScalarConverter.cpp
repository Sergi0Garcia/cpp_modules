/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:11:34 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/08 14:13:25 by segarcia         ###   ########.fr       */
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
  if (std::isprint(_input[0]) && std::isalpha(_input[0]))
    return (true);
  return (false);
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

  if (_input.empty())
    return (false);
  if (_input[i] == '+' || _input[i] == '-')
    i = 1;

  int val = _input.find('.');
  std::cout << "val: " << val << std::endl;

  while (_input[i]) {
    if (i == static_cast<int>(_input.length() - 1)) {
      if (_input[i] != 'f')
        return (false);
      else
        return (true);
    }
    if (!std::isdigit(_input[i]))
      return (false);
    i++;
  }
  return (true);
}

void ScalarConverter::convert(void) {
  std::cout << "[ScalarConverter] converting ... " << std::endl;
  std::cout << "[ScalarConverter] is_char: " << is_char() << std::endl;
  std::cout << "[ScalarConverter] is_int: " << is_int() << std::endl;
  std::cout << "[ScalarConverter] is_float: " << is_float() << std::endl;
}