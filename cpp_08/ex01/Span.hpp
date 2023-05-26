/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:20:59 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/26 12:58:50 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <list>
#include <set>
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
  template <typename T> void addNumbers(const T &container);
  std::vector<int> generateRandom(int size);
  int shortestSpan(void) const;
  int longestSpan(void) const;
  void printArr(void) const;

  class MaxCapacity : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Error: vector size max capacity";
    }
  };

  class NoNumbers : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Error: no numbers stored in vector must be > 1";
    }
  };
};
