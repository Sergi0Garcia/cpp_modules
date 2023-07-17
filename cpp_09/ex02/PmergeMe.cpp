/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:55:52 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/17 12:50:09 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Utils.hpp"
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <utility>
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

void printVectorD(const std::deque<int> &vec, std::string str) {
  std::cout << str << std::endl;
  for (std::deque<int>::const_iterator it = vec.begin(); it != vec.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void printPoints(std::vector<std::pair<int, int> > arr, std::string str) {
	std::cout << str << std::endl;
	for(size_t i = 0; i < arr.size(); i++) {
		std::cout << "P[" << i << "] = " << arr[i].first << ", " << arr[i].second << std::endl;
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
        char *end_ptr = &tmp[0] + tmp.size();
        long value = std::strtol(tmp.c_str(), &end_ptr, 10);
        if (value > std::numeric_limits<int>::max())
          return (print_error(NUM_OUT_OF_RANGE));
        if (!isValueInVector(_vector, value)) {
          _vector.push_back(static_cast<int>(value));
          _deque.push_back(static_cast<int>(value));
        }
      }
    }
  }
  return (true);
}

int jacobsthal(int n) {
  if (n == 0)
    return (0);
  if (n == 1)
    return (1);
  return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

std::vector<int> build_sequence_vector(int b_len) {
  std::vector<int> jacob_sequence;
  std::vector<int> full_sequence;
  int jacob_index = 2;

  while (jacobsthal(jacob_index) < b_len + 2 - 1) {
    jacob_sequence.push_back(jacobsthal(jacob_index));
    jacob_index += 1;
  }

  for (size_t i = 0; i < jacob_sequence.size(); i++) {
    if (i == 0)
      full_sequence.push_back(jacob_sequence[i]);
    else {
      full_sequence.push_back(jacob_sequence[i]);
      int range = jacob_sequence[i] - jacob_sequence[i - 1] - 1;
      for (int j = 0; j < range; j++)
        full_sequence.push_back(jacob_sequence[i] - (j + 1));
    }
  }
  for (int i = 0; b_len > static_cast<int>(full_sequence.size()); i++)
    full_sequence.push_back(jacob_sequence[jacob_sequence.size() - 1] + i + 1);
  return (full_sequence);
}

std::deque<int> build_sequence_deque(int b_len) {
  std::deque<int> jacob_sequence;
  std::deque<int> full_sequence;
  int jacob_index = 2;

  while (jacobsthal(jacob_index) < b_len + 2 - 1) {
    jacob_sequence.push_back(jacobsthal(jacob_index));
    jacob_index += 1;
  }

  for (size_t i = 0; i < jacob_sequence.size(); i++) {
    if (i == 0)
      full_sequence.push_back(jacob_sequence[i]);
    else {
      full_sequence.push_back(jacob_sequence[i]);
      int range = jacob_sequence[i] - jacob_sequence[i - 1] - 1;
      for (int j = 0; j < range; j++)
        full_sequence.push_back(jacob_sequence[i] - (j + 1));
    }
  }
  for (int i = 0; b_len > static_cast<int>(full_sequence.size()); i++)
    full_sequence.push_back(jacob_sequence[jacob_sequence.size() - 1] + i + 1);
  return (full_sequence);
}

bool PmergeMe::init(void) {
  if (!parse_input())
    return (false);
  this->_vjacob = build_sequence_vector(_vector.size() / 2);
  this->_djacob = build_sequence_deque(_deque.size() / 2);
  return (true);
}


int binarySearchPairs(std::vector<std::pair<int, int> > arr, int key, int start, int end) {
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid].first == key) {
      return mid; // Key already exists at index 'mid'
    } else if (arr[mid].first < key) {
      start = mid + 1; // Search in the right half
    } else {
      end = mid - 1; // Search in the left half
    }
  }
  return start; // Return the insertion point
}

int binarySearchPairsDeque(std::deque<std::pair<int, int> > arr, int key, int start, int end) {
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid].first == key) {
      return mid; // Key already exists at index 'mid'
    } else if (arr[mid].first < key) {
      start = mid + 1; // Search in the right half
    } else {
      end = mid - 1; // Search in the left half
    }
  }
  return start; // Return the insertion point
}

int binarySearch(const std::vector<int> &vec, int key, int start, int end) {
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (vec[mid] == key) {
      return mid; // Key already exists at index 'mid'
    } else if (vec[mid] < key) {
      start = mid + 1; // Search in the right half
    } else {
      end = mid - 1; // Search in the left half
    }
  }
  return start; // Return the insertion point
}

int binarySearchD(const std::deque<int> &vec, int key, int start, int end) {
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (vec[mid] == key) {
      return mid; // Key already exists at index 'mid'
    } else if (vec[mid] < key) {
      start = mid + 1; // Search in the right half
    } else {
      end = mid - 1; // Search in the left half
    }
  }
  return start; // Return the insertion point
}


bool PmergeMe::sort_vector(void) {
  // define straggler
  if ((_vector.size() % 2) == 1) {
    _has_straggler = true;
    _straggler = _vector.back();
    _vector.pop_back();
  }
  // create_pairs
  std::vector<std::pair<int, int> > arr;
  for (size_t i = 0; i < (_vector.size() / 2); i++) {
    arr.push_back(std::make_pair(_vector[2 * i + 0], _vector[2 * i + 1]));
  }
  // sort pairs [a, b] DESC (a > b)
  for (size_t i = 0; i < (_vector.size() / 2); i++) {
    if (arr[i].second > arr[i].first)
      std::swap(arr[i].first, arr[i].second);
  }

  // sort pairs depending on a
	std::vector<std::pair<int, int> > sorted_arr;
  for (size_t i = 0; i < _vector.size() / 2; i++) {
		if (i == 0)
			sorted_arr.push_back(arr[i]);
		else {
			 int position = binarySearchPairs(sorted_arr, arr[i].first, 0, sorted_arr.size() - 1);
			 sorted_arr.insert(sorted_arr.begin() + position,arr[i]);
		}
  }
  // create main chain
  std::vector<int> main_chain;
  for (size_t i = 0; i < _vector.size() / 2; i++)
    main_chain.push_back(sorted_arr[i].first);
  // insertion sort with jacob numbers
  for (size_t i = 0; i < _vector.size() / 2; i++) {
    int jacob_pos = _vjacob[i] - 1;
    int value = sorted_arr[jacob_pos].second;
    int position = binarySearch(main_chain, value, 0, main_chain.size() - 1);
    main_chain.insert(main_chain.begin() + position, value);
  }
	if (_has_straggler) {
		int position = binarySearch(main_chain, _straggler, 0, main_chain.size() - 1);
    main_chain.insert(main_chain.begin() + position, _straggler);
	}
	_sorted_vector = main_chain;
  return (true);
}

bool PmergeMe::sort_deque(void) {
  // define straggler
  if ((_deque.size() % 2) == 1) {
    _has_straggler = true;
    _straggler = _deque.back();
    _deque.pop_back();
  }
  // create_pairs
  std::deque<std::pair<int, int> > arr;
  for (size_t i = 0; i < (_deque.size() / 2); i++) {
    arr.push_back(std::make_pair(_deque[2 * i + 0], _deque[2 * i + 1]));
  }
  // sort pairs [a, b] DESC (a > b)
  for (size_t i = 0; i < (_deque.size() / 2); i++) {
    if (arr[i].second > arr[i].first)
      std::swap(arr[i].first, arr[i].second);
  }

  // sort pairs depending on a
	std::deque<std::pair<int, int> > sorted_arr;
  for (size_t i = 0; i < _deque.size() / 2; i++) {
		if (i == 0)
			sorted_arr.push_back(arr[i]);
		else {
			 int position = binarySearchPairsDeque(sorted_arr, arr[i].first, 0, sorted_arr.size() - 1);
			 sorted_arr.insert(sorted_arr.begin() + position,arr[i]);
		}
  }
  // create main chain
  std::deque<int> main_chain;
  for (size_t i = 0; i < _deque.size() / 2; i++)
    main_chain.push_back(sorted_arr[i].first);
  // insertion sort with jacob numbers
  for (size_t i = 0; i < _deque.size() / 2; i++) {
    int jacob_pos = _djacob[i] - 1;
    int value = sorted_arr[jacob_pos].second;
    int position = binarySearchD(main_chain, value, 0, main_chain.size() - 1);
    main_chain.insert(main_chain.begin() + position, value);
  }
	if (_has_straggler) {
		int position = binarySearchD(main_chain, _straggler, 0, main_chain.size() - 1);
    main_chain.insert(main_chain.begin() + position, _straggler);
	}
	_sorted_deque = main_chain;
  return (true);
}

bool PmergeMe::sort_both(void)
{
	clock_t start_vector = std::clock();
	sort_vector();
	clock_t end_vector = std::clock();
	clock_t start_deque = std::clock();
	sort_deque();
	clock_t end_deque = std::clock();
	std::cout << "Before: ";
	printVector(_vector);
	std::cout << "After: ";
	printVector(_sorted_vector);
	std::cout << "std::vector[" << _vector.size() << "] = ";
	print_time_diff(start_vector, end_vector);
	std::cout << "std::deque[" << _deque.size() << "] = ";
	print_time_diff(start_deque, end_deque);
	return (true);
}