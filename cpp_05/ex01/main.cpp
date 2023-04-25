/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:12:21 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/25 13:33:20 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void default_test_f(void) {
  Form form1("A1", 10, 5);
  Form form2(form1);
  std::cout << form1;
  std::cout << form2;
  std::cout << &form1 << " - " << &form2 << std::endl;
  // system("leaks ex01");
  return;
}

void default_test_b(void) {
  Bureaucrat men0;
  Bureaucrat men1("men1", 10);
  Bureaucrat men2(men1);

  std::cout << men0;
  std::cout << men1;
  std::cout << men2;

  men0 = men1;
  std::cout << men0;

  // system("leaks ex01");
  std::cout << std::endl;
  return;
}

int main(void) {
  // default_test_f();
  // default_test_b();
  try {
    Form a1("A1", 10, 5);
    Bureaucrat john("John", 11);
    john.signForm(a1);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  // system("leaks ex00");
  return (0);
}