/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:12:21 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/15 11:10:34 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void default_test(void) {
  Bureaucrat men0;
  Bureaucrat men1("men1", 10);
  Bureaucrat men2(men1);

  std::cout << men0;
  std::cout << men1;
  std::cout << men2;

  men0 = men1;
  std::cout << men0;

  // system("leaks ex00");
  std::cout << std::endl;
  return;
}

int main(void) {
  // default_test();
  try {
    Bureaucrat john("John", 10);
    // Bureaucrat john("John", 151);
    // Bureaucrat smith("Smith", -10);
    john.decrementGrade();
    john.incrementGrade();
    john.incrementGrade();
    std::cout << john;
  } catch (const std::exception &e) {
    std::cout << "ERROR: " << e.what() << std::endl;
  }
  // system("leaks ex00");
  return (0);
}