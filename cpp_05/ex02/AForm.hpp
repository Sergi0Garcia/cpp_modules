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
  ~AForm();

  std::string getName(void) const;
  virtual bool isSigned(void) const = 0;
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

std::ostream &operator<<(std::ostream &stream, AForm const &orm);

#endif