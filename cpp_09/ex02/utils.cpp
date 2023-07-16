/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:52:23 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/16 15:57:32 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "Errors.hpp"
#include <cctype>

bool print_error(ERROR err) {
  std::cout << RED << "Error: ";
  switch (err) {
  case INVALID_ARGC:
    std::cout << "usage: must have at least 2 numbers";
    break;
  case MUST_BE_NUMBER:
    std::cout << "usage: not valid number: must be positive int";
    break;
  default:
    std::cout << "unknown error";
    break;
  }
  std::cout << RESET << std::endl;
  // Always returning false
  return (false);
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