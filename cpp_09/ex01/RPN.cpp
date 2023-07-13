/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:07:20 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/13 14:29:09 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string input) : _stk(), _input(input) {}

RPN::RPN(const RPN &other) { *this = other; }

RPN &RPN::operator=(const RPN &other) {
  if (this == &other)
    return (*this);
  this->_stk = other._stk;
  this->_input = other._input;
  return (*this);
}

RPN::~RPN() {}

bool RPN::run(void) {
  char c;
  long num1, num2, ans;

  this->_input = trimWhitespace(_input);
  for (size_t i = 0; i < _input.length(); i++) {
    c = _input[i];
    if (isdigit(c))
      _stk.push((c - '0'));
    else {
      if (c == ' ')
        continue;
      else if (_stk.size() < 2)
        return (print_error(STACK_SIZE));
      num1 = _stk.top();
      _stk.pop();
      num2 = _stk.top();
      _stk.pop();
      switch (c) {
      case '+':
        _stk.push(num2 + num1);
        break;
      case '-':
        _stk.push(num2 - num1);
        break;
      case '/':
        _stk.push(num2 / num1);
        break;
      case '*':
        _stk.push(num2 * num1);
        break;
      default:
        return (print_error(MISSING_OPERATOR));
      }
    }
  }
  if (is_empty_str(_input))
    return (print_error(EMPTY_STRING));
  if (_stk.size() != 1)
    return (print_error(MISSING_OPERATOR_MANY_NUMBERS));
  ans = _stk.top();
  if (ans < std::numeric_limits<int>::min() ||
      ans > std::numeric_limits<int>::max())
    return (print_error(INT_OUT_OF_RANGE));
  std::cout << GREEN << ans << RESET << std::endl;
  return (true);
}
