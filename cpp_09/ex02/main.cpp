/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:58:44 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/17 00:07:54 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Utils.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>

void print_time(clock_t start, clock_t end) {
  clock_t res;
  std::string micro = "\xC2\xB5";

  res = static_cast<double>(end - start) / CLOCKS_PER_SEC * 10000000;
  if (res > 10000)
    std::cout << res / 1000 << "ms" << std::endl;
  else
    std::cout << res << micro << "s" << std::endl;
}
void printVectorJ(const std::vector<int> &vec) {
  for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int jacobsthal(int n) {
  if (n == 0)
    return (0);
  if (n == 1)
    return (1);
  return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void build_sequence(int b_len) {
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
  printVectorJ(full_sequence);
}

int main(int argc, char **argv) {
  if (!valid_argc(argc))
    return (1);
  if (!valid_argv(argv, argc))
    return (1);
  PmergeMe merger(argv, argc);
  clock_t start = std::clock();
  merger.merge_insertion_sort();
  clock_t end = std::clock();
  print_time(start, end);
  build_sequence(100);
  // system("leaks PmergeMe");
  return (0);
}
