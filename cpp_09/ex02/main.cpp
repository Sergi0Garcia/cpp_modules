/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:58:44 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/16 16:25:56 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Utils.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

void print_time(clock_t start, clock_t end) {
  clock_t res;
  std::string micro = "\xC2\xB5";

  res = static_cast<double>(end - start) / CLOCKS_PER_SEC * 10000000;
  if (res > 10000)
    std::cout << res / 1000 << "ms" << std::endl;
  else
    std::cout << res << micro << "s" << std::endl;
}

int main(int argc, char **argv) {
  if (!valid_argc(argc))
    return (1);
  if (!valid_argv(argv, argc))
    return (1);
  PmergeMe merger(argv, argc);
  clock_t start = std::clock();
  merger.parse_input();
  clock_t end = std::clock();
  print_time(start, end);
  // system("leaks PmergeMe");
  return (0);
}
