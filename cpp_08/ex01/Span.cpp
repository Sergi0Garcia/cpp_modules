/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:48:50 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/23 12:23:15 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Colors.hpp"
#include <vector>

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

// prints array ordered
void Span::printArr(void) const {
  std::vector<int> copy = _arr;
  std::sort(copy.begin(), copy.end());
  for (size_t i = 0; i < copy.size(); i++) {
    std::cout << copy[i] << std::endl;
  }
}

void Span::addNumber(int num) {
  if (this->_arr.size() >= this->_n)
    throw Span::MaxCapacity();
  this->_arr.push_back(num);
}

template <typename T> void Span::addNumbers(const T &container) {
  typedef typename T::value_type value_type;
  typename T::const_iterator it;
  for (it = container.begin(); it != container.end(); ++it) {
    const value_type &value = *it;
    _arr.push_back(value);
  }
  std::cout << std::endl;
}

template void Span::addNumbers(const std::vector<int> &container);
template void Span::addNumbers(const std::list<int> &container);

std::vector<int> Span::generateRandom(int size) {
  std::vector<int> random;
  std::srand(std::time(NULL));
  for (int i = 0; i < size; i++) {
    random.push_back(std::rand() % 10000 + 1);
  }
  return (random);
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
  std::sort(copy.begin(), copy.end());
  int longest_distance = abs(copy.front() - copy.back());
  return (longest_distance);
}