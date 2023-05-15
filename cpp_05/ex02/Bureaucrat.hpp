/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:13:55 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/15 10:46:14 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "AForm.hpp"
#include <iostream>
#include <ostream>

// Grade ranges between 1 and 150
// Grade 1 (highest possible grade)
// Grade 150 (Lowest possible grade)

class Bureaucrat {
private:
  std::string const _name;
  int _grade;

public:
  Bureaucrat(void);
  Bureaucrat(const std::string name, const int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat(void);

  std::string getName(void) const;
  int getGrade(void) const;
  void incrementGrade(void);
  void decrementGrade(void);

  void signForm(AForm &form);
  void executeForm(AForm const &form);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() { return "Grade is too high"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() { return "Grade is too low "; }
  };
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &other);

#endif