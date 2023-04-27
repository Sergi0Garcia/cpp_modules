/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:41:03 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/25 13:31:01 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

AForm::AForm(const std::string name, const int requiredGradeSingIn,
             const int requiredGradeExecute)
    : _name(name), _isSigned(false), _requiredGradeSingIn(requiredGradeSingIn),
      _requiredGradeExecute(requiredGradeExecute) {
  std::cout << GREEN;
  std::cout << "[AForm] constructor created" << std::endl;
  std::cout << RESET;
}

AForm::AForm(const AForm &other)
    : _name(other._name), _requiredGradeSingIn(other._requiredGradeSingIn),
      _requiredGradeExecute(other._requiredGradeExecute) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[AForm] copy constructor created" << std::endl;
  std::cout << RESET;
}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    this->_isSigned = other._isSigned;
  }
  return (*this);
}

AForm::~AForm() {
  std::cout << RED;
  std::cout << "[AForm] deconstructor called" << std::endl;
  std::cout << RESET;
}

std::string AForm::getName(void) const { return (this->_name); }

bool AForm::isSigned(void) const { return (this->_isSigned); }

int AForm::getRequiredGradeSignIn(void) const {
  return (this->_requiredGradeSingIn);
}

int AForm::getRequiredGradeExecute(void) const {
  return (this->_requiredGradeExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->getRequiredGradeSignIn())
    throw AForm::GradeTooLowException();
  this->_isSigned = true;
  return;
}

std::ostream &operator<<(std::ostream &stream, AForm const &form) {
  stream << PURPLE << "[AForm] " << form.getName()
         << " is signed: " << form.isSigned()
         << " required sign in: " << form.getRequiredGradeSignIn()
         << " required execute: " << form.getRequiredGradeExecute() << std::endl
         << RESET;
  return (stream);
}