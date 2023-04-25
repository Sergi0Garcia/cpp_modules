/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:13:54 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/25 13:24:12 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>

class Bureaucrat;

class Form {
private:
  const std::string _name;
  bool _isSigned;
  const int _requiredGradeSingIn;
  const int _requiredGradeExecute;

public:
  Form(const std::string name, const int requiredGradeSingIn,
       const int requiredGradeExecute);
  Form(const Form &other);
  Form &operator=(const Form &other);
  ~Form();

  std::string getName(void) const;
  bool isSigned(void) const;
  int getRequiredGradeSignIn(void) const;
  int getRequiredGradeExecute(void) const;
  void beSigned(const Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() { return "Grade is too high"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() { return "Grade is too low "; }
  };
};

std::ostream &operator<<(std::ostream &stream, Form const &form);

#endif