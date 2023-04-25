/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:41:03 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/25 13:31:01 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

Form::Form(const std::string name, const int requiredGradeSingIn,
           const int requiredGradeExecute)
    : _name(name), _isSigned(false), _requiredGradeSingIn(requiredGradeSingIn),
      _requiredGradeExecute(requiredGradeExecute) {
  std::cout << GREEN;
  std::cout << "[Form] constructor created" << std::endl;
  std::cout << RESET;
}

Form::Form(const Form &other)
    : _name(other._name), _requiredGradeSingIn(other._requiredGradeSingIn),
      _requiredGradeExecute(other._requiredGradeExecute) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[Form] copy constructor created" << std::endl;
  std::cout << RESET;
}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    this->_isSigned = other._isSigned;
  }
  return (*this);
}

Form::~Form() {
  std::cout << RED;
  std::cout << "[Form] deconstructor called" << std::endl;
  std::cout << RESET;
}

std::string Form::getName(void) const { return (this->_name); }

bool Form::isSigned(void) const { return (this->_isSigned); }

int Form::getRequiredGradeSignIn(void) const {
  return (this->_requiredGradeSingIn);
}

int Form::getRequiredGradeExecute(void) const {
  return (this->_requiredGradeExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->getRequiredGradeSignIn())
    throw Form::GradeTooLowException();
  this->_isSigned = true;
  return;
}

std::ostream &operator<<(std::ostream &stream, Form const &form) {
  stream << PURPLE << "[Form] " << form.getName()
         << " is signed: " << form.isSigned()
         << " required sign in: " << form.getRequiredGradeSignIn()
         << " required execute: " << form.getRequiredGradeExecute() << std::endl
         << RESET;
  return (stream);
}