/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:12:21 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/27 14:14:28 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

void test(void) {
  Intern someRandomIntern;
  AForm *rrf;
  rrf = someRandomIntern.makeForm("robotomy request", "Bender");

  free(rrf);
  // system("leaks ex03");
}

int main(void) {
  test();
  // system("leaks ex03");
  return (0);
}