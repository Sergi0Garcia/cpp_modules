/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:08:34 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/11 12:34:51 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Types.hpp"
#include "Colors.hpp"

Base::~Base() {}

Base *generate(void) {
  int random = std::rand();
  if (random % 3 == 0)
    return (new A);
  else if (random % 3 == 1)
    return (new B);
  else
    return (new C);
}

void identify(Base *p) {
  std::cout << BLUE;
  if (dynamic_cast<A *>(p))
    std::cout << "[Types][*] Identified as A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "[Types][*] Identified as B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "[Types][*] Identified as C" << std::endl;
  else
    std::cout << "[Types][*] Not identified" << std::endl;
  std::cout << RESET;
}

void identify(Base &p) {
  std::cout << PURPLE;
  try {
    A &a = dynamic_cast<A &>(p);
    std::cout << "[Types][&] Identified as A" << std::endl;
    std::cout << RESET;
    (void)a;
    return;
  } catch (const std::exception &) {
  }
  try {
    B &b = dynamic_cast<B &>(p);
    std::cout << "[Types][&] Identified as B" << std::endl;
    std::cout << RESET;
    (void)b;
    return;
  } catch (const std::exception &) {
  }
  try {
    C &c = dynamic_cast<C &>(p);
    std::cout << "[Types][&] Identified as C" << std::endl;
    std::cout << RESET;
    (void)c;
    return;
  } catch (const std::exception &) {
  }
  std::cout << "[Types][&] Not identified" << std::endl;
}