/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:55:52 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/16 18:55:16 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Utils.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

PmergeMe::PmergeMe(char **input, int argc)
    : _input(input), _argc(argc), _has_straggler(false), _straggler(-1) {}

PmergeMe::~PmergeMe() {}

void printVector(const std::vector<int> &vec) {
  for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
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
        char *end_ptr = &tmp[0] + tmp.size();
        long value = std::strtol(tmp.c_str(), &end_ptr, 10);
        if (value > std::numeric_limits<int>::max())
          return (print_error(NUM_OUT_OF_RANGE));
        if (!isValueInVector(_vector, value))
          _vector.push_back(static_cast<int>(value));
      }
    }
  }
  printVector(_vector);
  return (true);
}

bool PmergeMe::merge_insertion_sort(void) {
  parse_input();

  // define straggler
  if ((_vector.size() % 2) == 1) {
    _has_straggler = true;
    _straggler = _vector.back();
    _vector.pop_back();
  }

  // create_pairs
  int arr[_vector.size() / 2][2];
  for (size_t i = 0; i < (_vector.size() / 2); i++) {
    arr[i][0] = _vector[2 * i + 0];
    arr[i][1] = _vector[2 * i + 1];
  }

  // sort pairs
  for (size_t i = 0; i < (_vector.size() / 2); i++) {
    int tmp = 0;
    if (arr[i][0] > arr[i][1]) {
      tmp = arr[i][1];
      arr[i][1] = arr[i][0];
      arr[i][0] = tmp;
    }
  }

  for (size_t i = 0; i < _vector.size() / 2; i++) {
    std::cout << "P[" << i << "]: " << arr[i][0] << ", " << arr[i][1]
              << std::endl;
  }

  return (true);
}