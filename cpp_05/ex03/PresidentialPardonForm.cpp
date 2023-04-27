/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:20:15 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/27 13:22:08 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
  std::cout << GREEN;
  std::cout << "[PresidentialPardonForm] default constructor created"
            << std::endl;
  std::cout << RESET;
  return;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[PresidentialPardonForm] copy constructor created" << std::endl;
  std::cout << RESET;
  return;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
    this->_target = other._target;
  }
  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
  std::cout << RED;
  std::cout << "[PresidentialPardonForm] destructor called" << std::endl;
  std::cout << RESET;
  return;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  if (!this->isSigned())
    throw AForm::FormNotSigned();
  if (executor.getGrade() > this->getRequiredGradeExecute())
    throw AForm::GradeTooLowException();
  std::cout << BLUE;
  std::cout << "[PresidentialPardonForm] " << this->_target
            << " has been pardoned by Zaphod Beeblebrox." << std::endl;
  std::cout << RESET;
}