/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:31:45 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/25 14:04:10 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Colors.hpp"

Bureaucrat::Bureaucrat(void) : _name("default bureaucrat"), _grade(150) {
  std::cout << GREEN;
  std::cout << "[Bureaucrat] default constructor created" << std::endl;
  std::cout << RESET;
  return;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  this->_grade = grade;
  std::cout << GREEN;
  std::cout << "[Bureaucrat] constructor created" << std::endl;
  std::cout << RESET;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
  std::cout << YELLOW;
  std::cout << "[Bureaucrat] copy constructor created" << std::endl;
  std::cout << RESET;
  *this = other;
  return;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->_name = other._name;
    this->_grade = other._grade;
  }
  return (*this);
}

Bureaucrat::~Bureaucrat(void) {
  std::cout << RED;
  std::cout << "[Bureaucrat] destructor called" << std::endl;
  std::cout << RESET;
  return;
}

std::string Bureaucrat::getName(void) const { return (this->_name); }

int Bureaucrat::getGrade(void) const { return (this->_grade); }

void Bureaucrat::incrementGrade(void) {
  if (this->getGrade() - 1 < 1)
    throw Bureaucrat::GradeTooHighException();
  this->_grade -= 1;
  std::cout << BLUE;
  std::cout << "[Bureaucrat] grade incrementend by (-1)" << std::endl;
  std::cout << RESET;
  return;
}

void Bureaucrat::decrementGrade(void) {
  if (this->getGrade() + 1 > 150)
    throw Bureaucrat::GradeTooLowException();
  this->_grade += 1;
  std::cout << BLUE;
  std::cout << "[Bureaucrat] grade decremented by (+1)" << std::endl;
  std::cout << RESET;
  return;
}

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << "[Bureaucrat] ";
    std::cout << this->getName() << " signed " << form.getName();
    std::cout << std::endl;
  } catch (const std::exception &e) {
    std::cout << "[Bureaucrat] ";
    std::cout << this->getName() << " couldn't sign " << form.getName();
    std::cout << " becauase " << e.what();
    std::cout << std::endl;
  }
  return;
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &other) {
  stream << PURPLE << "[Bureaucrat] " << other.getName()
         << " grade: " << other.getGrade() << std::endl
         << RESET;
  return (stream);
}