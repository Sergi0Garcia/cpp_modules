/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:58:44 by segarcia          #+#    #+#             */
/*   Updated: 2023/06/06 08:57:04 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include <iostream>
#include <stdio.h>

bool valid_input(const char *file_path) {
  if (static_cast<std::string>(file_path).empty())
    return (false);
  FILE *file = std::fopen(file_path, "r");
  if (file == NULL)
    return (false);
  std::fclose(file);
  return (true);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << RED << "error: usage: <path>" << RESET << std::endl;
    return (1);
  }
  if (!valid_input(argv[1])) {
    std::cout << RED << "error: invalid input" << RESET << std::endl;
    return (1);
  }
  (void)argv;
  return (0);
}