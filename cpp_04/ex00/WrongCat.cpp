/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:
 */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:24:12 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/16 13:24:17 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Colors.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
  std::cout << GREEN;
  std::cout << "[WrongCat] constructor called" << std::endl;
  std::cout << RESET;
};

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[WrongCat] copy constructor called" << std::endl;
  std::cout << RESET;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  if (this != &other) {
    WrongAnimal::operator=(other);
  }
  return (*this);
}

WrongCat::~WrongCat(void) {
  std::cout << RED;
  std::cout << "[WrongCat] destructor called" << std::endl;
  std::cout << RESET;
}

void WrongCat::makeSound(void) const {
  std::cout << BLUE;
  std::cout << "[WrongCat] sound 🔊" << std::endl;
  std::cout << RESET;
}
