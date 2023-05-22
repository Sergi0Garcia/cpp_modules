/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:48:50 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/22 13:51:53 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Colors.hpp"
#include <climits>
#include <limits>

Span::Span(unsigned int n) : _n(n) {
  std::cout << GREEN;
  std::cout << "[Span] constructor called" << std::endl;
  std::cout << RESET;
}

Span::~Span(void) {
  std::cout << RED;
  std::cout << "[Span] destructor called" << std::endl;
  std::cout << RESET;
}

Span::Span(const Span &other) {
  std::cout << YELLOW;
  std::cout << "[Span] copy constructor called" << std::endl;
  std::cout << RESET;
  *this = other;
}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    this->_n = other._n;
  }
  return (*this);
}

void Span::addNumber(int num) {
  if (this->_arr.size() >= this->_n)
    throw Span::MaxCapacity();
  this->_arr.push_back(num);
}

int Span::shortestSpan(void) const {
  if (_arr.empty() || _n <= 1)
    throw Span::NoNumbers();
  std::vector<int> copy = _arr;
  int shortest_distance = std::numeric_limits<int>::max();
  int tmp = 0;
  std::sort(copy.begin(), copy.end());
  for (int i = 0; i < static_cast<int>(copy.size()); i++) {
    if (copy[i + 1]) {
      tmp = abs(copy[i] - copy[i + 1]);
      if (tmp < shortest_distance)
        shortest_distance = tmp;
    }
  }
  return (shortest_distance);
}

int Span::longestSpann(void) const {
  if (_arr.empty() || _n <= 1)
    throw Span::NoNumbers();
  std::vector<int> copy = _arr;
  int longest_distance = 0;
  int tmp = 0;
  std::sort(copy.begin(), copy.end());
  for (int i = 0; i < static_cast<int>(copy.size() - 1); i++) {
    tmp = abs(copy.front() - copy.back());
    if (tmp > longest_distance)
      longest_distance = tmp;
  }
  return (longest_distance);
}