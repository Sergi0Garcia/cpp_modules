/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:12:21 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/15 11:03:19 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  try {
    ShrubberyCreationForm shrubbery("s_target");
    RobotomyRequestForm robotomy("r_target");
    PresidentialPardonForm presidential("p_target");

    Bureaucrat john("John", 1);
    john.signForm(shrubbery);
    john.signForm(robotomy);
    john.signForm(presidential);
    john.executeForm(shrubbery);
    john.executeForm(robotomy);
    john.executeForm(robotomy);
    john.executeForm(presidential);
  } catch (const std::exception &e) {
    std::cout << "ERROR: " << e.what() << std::endl;
  }
  // system("leaks ex02");
  return (0);
}