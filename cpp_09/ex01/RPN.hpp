/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:13:52 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/13 14:29:08 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include "Errors.hpp"
#include "Utils.hpp"
#include <iostream>
#include <limits>
#include <stack>

class RPN {
private:
  std::stack<int> _stk;
  std::string _input;

public:
  RPN(std::string input);
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);
  ~RPN();

  bool run(void);
};

// // ----------------------------
// https://paodayag.dev/reverse-polish-notation-js-parser/
// https://medium.com/@ainayat865/reverse-polish-notation-rpn-with-stack-4551a5f54ae0
// https://www-stone.ch.cam.ac.uk/documentation/rrf/rpn.html#:~:text=In%20RPN%2C%20the%20numbers%20and,the%20top%20of%20the%20stack.
// ----------------------------
// 8 9 * 9 - 9 - 9 - 4 - 1 +
// 72 9 - 9 - 9 - 4 - 1 +
// 63 9 - 9 - 4 - 1 +
// 54 9 - 4 - 1 +
// 45 4 - 1 +
// 41 1 +
// ans = 42
// ----------------------------
// 7 7 * 7 -
// 49 7 -
// ans = 42
// ----------------------------
// 1 2 * 2 / 2 * 2 4 - +
// 2 2 / 2 * 2 4 - +
// 1 2 * 2 4 - +
// 2 2 4 - +
// 4 2 2 - +
// 2 - 4 = - 2
// -2 2 +
// ans = 0
// ----------------------------