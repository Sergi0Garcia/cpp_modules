/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:02:39 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/27 13:14:12 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
  std::cout << GREEN;
  std::cout << "[RobotomyRequestForm] default constructor created" << std::endl;
  std::cout << RESET;
  return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[RobotomyRequestForm] copy constructor created" << std::endl;
  std::cout << RESET;
  return;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    this->_target = other._target;
  }
  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
  std::cout << RED;
  std::cout << "[RobotomyRequestForm] destructor called" << std::endl;
  std::cout << RESET;
  return;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  if (!this->isSigned())
    throw AForm::FormNotSigned();
  if (executor.getGrade() > this->getRequiredGradeExecute())
    throw AForm::GradeTooLowException();
  static int i;
  if (i % 2 == 0) {
    std::cout << BLUE;
    std::cout << "[RobotomyRequestForm] " << this->_target
              << " has been robotomized!" << std::endl;
    std::cout << RESET;
  } else {
    std::cout << BLUE;
    std::cout << "[RobotomyRequestForm] robotomy failed!" << std::endl;
    std::cout << RESET;
  }
  i++;
}