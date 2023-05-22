/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:20:59 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/22 13:51:08 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

class Span {
private:
  unsigned int _n;
  std::vector<int> _arr;

public:
  Span(unsigned int n);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  void addNumber(int num);
  void addNumber(std::vector<int> range);
  int shortestSpan(void) const;
  int longestSpann(void) const;

  class MaxCapacity : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Error: vector size max capacity";
    }
  };

  class NoNumbers : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Error: no numbers stored in vector";
    }
  };
};
