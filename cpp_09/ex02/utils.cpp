/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:52:23 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/19 12:37:53 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "Errors.hpp"
#include <cctype>

bool print_error(ERROR err) {
  std::cout << RED << "Error: ";
  switch (err) {
  case INVALID_ARGC:
    std::cout << "usage: must have at least 2 args";
    break;
  case MUST_BE_NUMBER:
    std::cout << "not valid number: must be positive int";
    break;
  case NUM_OUT_OF_RANGE:
    std::cout << "not valid number: INT MAX";
    break;
  default:
    std::cout << "unknown error";
    break;
  }
  std::cout << RESET << std::endl;
  // Always returning false
  return (false);
}

void print_time_diff(clock_t start, clock_t end) {
  clock_t res;
  std::string micro = "\xC2\xB5";

  res = static_cast<double>(end - start) / CLOCKS_PER_SEC * 10000000;
  if (res > 10000)
    std::cout << res / 1000 << "ms" << std::endl;
  else
    std::cout << res << micro << "s" << std::endl;
}

bool valid_argc(int argc) {
  if (argc < 2)
    return (print_error(INVALID_ARGC));
  return (true);
}

bool valid_argv(char **str, int argc) {
  int i = 1;
  int j = 0;
  while (i < argc && str[i][0]) {
    j = 0;
    while (str[i][j]) {
      if (!(std::isdigit(str[i][j]) || str[i][j] == ' '))
        return (print_error(MUST_BE_NUMBER));
      j++;
    }
    i++;
  }
  return (true);
}