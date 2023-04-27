/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:35:48 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/27 14:14:34 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Colors.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
  std::cout << GREEN;
  std::cout << "[Intern] default constructor created" << std::endl;
  std::cout << RESET;
  return;
}

Intern::Intern(const Intern &other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[Intern] copy constructor created" << std::endl;
  std::cout << RESET;
  return;
}

Intern &Intern::operator=(const Intern &other) {
  if (this != &other) {
    *this = other;
  }
  return (*this);
}

Intern::~Intern() {
  std::cout << RED;
  std::cout << "[Intern] destructor called" << std::endl;
  std::cout << RESET;
  return;
}

AForm *Intern::createShrubbery(std::string target) {
  return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomy(std::string target) {
  return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidential(std::string target) {
  return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target) {
  std::string forms[] = {"shrubbery creation", "robotomy request",
                         "presidential pardon"};
  t_intern Aforms[] = {&Intern::createShrubbery, &Intern::createRobotomy,
                       &Intern::createPresidential};
  for (int i = 0; i < 3; i++) {
    if (name == forms[i]) {
      std::cout << BLUE;
      std::cout << "[Intern] creates " << forms[i] << " form!" << std::endl;
      std::cout << RESET;
      return (this->*Aforms[i])(target);
    }
  }
  std::cout << BLUE;
  std::cout << "[Intern] form name not found :(" << std::endl;
  std::cout << RESET;
  return (NULL);
};
