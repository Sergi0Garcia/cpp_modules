/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:52:23 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/19 12:24:14 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

bool print_error(ERROR err) {
  std::cout << RED << "Error: ";
  switch (err) {
  case INVALID_ARGC:
    std::cout << "usage: <RPN>";
    break;
  case EMPTY_STRING:
    std::cout << "invalid input: empty string";
    break;
  case INVALID_CHAR:
    std::cout << "invalid input: invalid char";
    break;
  case STACK_SIZE:
    std::cout << "invalid input: must match operation with numbers";
    break;
  case MISSING_OPERATOR:
    std::cout << "invalid input: required operator (+ - / *)";
    break;
  case MISSING_OPERATOR_MANY_NUMBERS:
    std::cout << "invalid input: check format of numbers and operations";
    break;
  case NUMBER_LESS_THAN_10:
    std::cout << "invalid input: number must be less than 10 with 1 char";
    break;
  case INT_OUT_OF_RANGE:
    std::cout << "result: out of range";
    break;
  default:
    std::cout << "unknown error";
    break;
  }
  std::cout << RESET << std::endl;
  // Always returning false
  return (false);
}

bool valid_argc(int argc) {
  if (argc != 2)
    return (print_error(INVALID_ARGC));
  return (true);
}

bool valid_input(std::string str) {
  if (str.empty())
    return (print_error(EMPTY_STRING));
  for (size_t i = 0; i < str.length(); i++) {
    if (std::isdigit(str[i]) && std::isdigit(str[i + 1]))
      return (print_error(NUMBER_LESS_THAN_10));
    if (str[i] == '.' || str[i] == ',')
      return (print_error(INVALID_CHAR));
    if (!(std::isdigit(str[i]) || str[i] == '-' || str[i] == '+' ||
          str[i] == '*' || str[i] == '/' || str[i] == ' '))
      return (print_error(INVALID_CHAR));
  }
  return (true);
}

std::string trimWhitespace(const std::string str) {
  size_t start = str.find_first_not_of(" \t\n\r");
  size_t end = str.find_last_not_of(" \t\n\r");
  if (start == std::string::npos) {
    return "";
  }
  return str.substr(start, end - start + 1);
}

bool is_empty_str(std::string str) {
  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] != ' ')
      return (false);
  }
  return (true);
}