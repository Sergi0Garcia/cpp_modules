/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:11:34 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/10 14:16:07 by segarcia         ###   ########.fr       */
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

bool ScalarConverter::is_keyword() const {
  std::string keywords[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
  for (int i = 0; i < 6; i++) {
    if (_input == keywords[i])
      return (true);
  }
  return (false);
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

void ScalarConverter::print_keyword(void) const {
  std::cout << BLUE;
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  if (_input == "nanf" || _input == "nan") {
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
  } else if (_input == "+inff" || _input == "+inf") {
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
  } else if (_input == "-inff" || _input == "-inf") {
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
  }
  std::cout << RESET;
}

void ScalarConverter::print_types(void) const {
  std::cout << BLUE;
  if (std::isprint(_char))
    std::cout << "[ScalarConverter] char: " << _char << std::endl;
  else
    std::cout << "[ScalarConverter] char: not printable" << std::endl;
  if (_float < static_cast<float>(INT_MIN) - 1 ||
      _float > static_cast<float>(INT_MAX) + 1 ||
      _double < static_cast<double>(INT_MIN) - 1 ||
      _double > static_cast<double>(INT_MAX) + 1)
    std::cout << "[ScalarConverter] int: out of range " << std::endl;
  else
    std::cout << "[ScalarConverter] int: " << _int << std::endl;
  std::cout << "[ScalarConverter] float: " << _float << std::endl;
  std::cout << "[ScalarConverter] double: " << _double << std::endl;
  std::cout << RESET;
}

void ScalarConverter::cast_char(void) {
  _char = static_cast<char>(_input[0]);
  _int = static_cast<int>(_char);
  _float = static_cast<float>(_char);
  _double = static_cast<double>(_char);
}

void ScalarConverter::cast_int(void) {
  _int = static_cast<int>(std::strtol(_input.c_str(), NULL, 10));
  _char = static_cast<char>(_int);
  _float = static_cast<float>(_int);
  _double = static_cast<double>(_int);
}

void ScalarConverter::cast_float(void) {
  _float = static_cast<float>(std::strtof(_input.c_str(), NULL));
  _char = static_cast<char>(_float);
  _int = static_cast<int>(_float);
  _double = static_cast<double>(_float);
}

void ScalarConverter::cast_double(void) {
  _double = static_cast<double>(std::strtold(_input.c_str(), NULL));
  _char = static_cast<char>(_double);
  _int = static_cast<int>(_double);
  _float = static_cast<float>(_double);
}

void ScalarConverter::convert(void) {
  std::cout << PURPLE << "[ScalarConverter] converting ... " << RESET
            << std::endl;
  try {
    if (this->is_keyword()) {
      this->print_keyword();
      return;
    }
    if (this->is_char())
      this->cast_char();
    else if (this->is_int())
      this->cast_int();
    else if (this->is_float())
      this->cast_float();
    else if (this->is_double())
      this->cast_double();
    else
      throw ScalarConverter::InvalidInput();
    this->print_types();
  } catch (const std::exception &e) {
    std::cout << RED;
    std::cout << "[ScalarConverter] Error: " << e.what() << std::endl;
    std::cout << RESET;
  }
}