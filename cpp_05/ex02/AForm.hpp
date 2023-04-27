/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:13:54 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/25 13:24:12 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
private:
  const std::string _name;
  bool _isSigned;
  const int _requiredGradeSingIn;
  const int _requiredGradeExecute;

public:
  AForm(const std::string name, const int requiredGradeSingIn,
        const int requiredGradeExecute);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm();

  std::string getName(void) const;
  bool isSigned(void) const;
  int getRequiredGradeSignIn(void) const;
  int getRequiredGradeExecute(void) const;

  void beSigned(const Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() { return "Grade is too high"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() { return "Grade is too low "; }
  };

  class FormNotSigned : public std::exception {
  public:
    const char *what() const throw() { return "Form is not signed"; }
  };

  class FileCreationFailed : public std::exception {
  public:
    const char *what() const throw() { return "Error creating execution file"; }
  };
};

std::ostream &operator<<(std::ostream &stream, AForm const &orm);

#endif