/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:10:01 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/08 10:45:11 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
  std::cout << GREEN;
  std::cout << "[ShrubberyCreationForm] default constructor created"
            << std::endl;
  std::cout << RESET;
  return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[ShrubberyCreationForm] copy constructor created" << std::endl;
  std::cout << RESET;
  return;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    this->_target = other._target;
  }
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
  std::cout << RED;
  std::cout << "[ShrubberyCreationForm] destructor called" << std::endl;
  std::cout << RESET;
  return;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!this->isSigned())
    throw AForm::FormNotSigned();
  if (executor.getGrade() > this->getRequiredGradeExecute())
    throw AForm::GradeTooLowException();
  std::ofstream ofstream;
  std::string fileName;
  std::string target;

  target = this->_target;
  fileName = target.append("_shrubbery.txt");
  ofstream.open(fileName.c_str());
  if (ofstream.fail())
    throw AForm::FileCreationFailed();
  ofstream << "      *" << std::endl;
  ofstream << "     ***" << std::endl;
  ofstream << "    *****" << std::endl;
  ofstream << "   *******" << std::endl;
  ofstream << "  *********" << std::endl;
  ofstream << "     ***" << std::endl;
  ofstream << "     ***" << std::endl;
  ofstream.close();
}