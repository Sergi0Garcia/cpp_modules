/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:12:21 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/08 11:25:45 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Error: must have 1 argument" << std::endl;
    return (1);
  }
  ScalarConverter converter(argv[1]);

  // system("leaks ex00");
  return (0);
}