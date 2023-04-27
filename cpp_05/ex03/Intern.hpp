/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:31:17 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/27 14:11:19 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class Intern {
private:
  AForm *createShrubbery(std::string target);
  AForm *createRobotomy(std::string target);
  AForm *createPresidential(std::string target);

public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();

  AForm *makeForm(std::string name, std::string target);
};

typedef AForm *(Intern::*t_intern)(std::string target);

#endif