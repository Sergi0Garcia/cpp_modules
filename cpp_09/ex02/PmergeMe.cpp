/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:55:52 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/16 17:05:40 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

PmergeMe::PmergeMe(char **input, int argc) : _input(input), _argc(argc) {}

PmergeMe::~PmergeMe() {}

void printVector(const std::vector<int> &vec) {
  for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end();
       ++it) {
    std::cout << *it << std::endl;
  }
}

bool isValueInVector(const std::vector<int> &vec, int value) {
  return std::find(vec.begin(), vec.end(), value) != vec.end();
}

bool PmergeMe::parse_input(void) {
  for (int i = 1; i < _argc; i++) {
    std::istringstream iss(this->_input[i]);
    std::string tmp;
    while (std::getline(iss, tmp, ' ')) {
      if (!tmp.empty()) {
        char *endPtr = &tmp[0] + tmp.size();
        long value = std::strtol(tmp.c_str(), &endPtr, 10);
        if (value > std::numeric_limits<int>::max() ||
            value < std::numeric_limits<int>::min())
          return (false);
        if (!isValueInVector(_vector, value))
          _vector.push_back(static_cast<int>(value));
      }
    }
  }
  printVector(_vector);
  return (true);
}
