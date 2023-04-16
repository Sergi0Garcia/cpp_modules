/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:
 */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:21:04 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/16 13:21:16 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Colors.hpp"

WrongAnimal::WrongAnimal() : _type("default") {
  std::cout << GREEN;
  std::cout << "[WrongAnimal] default constructor called" << std::endl;
  std::cout << RESET;
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type) {
  std::cout << GREEN;
  std::cout << "[WrongAnimal] " << type << " constructor called" << std::endl;
  std::cout << RESET;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[WrongAnimal] copy constructor called" << std::endl;
  std::cout << RESET;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  if (this != &other) {
    this->_type = other._type;
  }
  return (*this);
}

void WrongAnimal::makeSound(void) const {
  std::cout << BLUE;
  std::cout << "[WrongAnimal] sound 🔊" << std::endl;
  std::cout << RESET;
}

std::string WrongAnimal::getType(void) const { return (this->_type); }

WrongAnimal::~WrongAnimal() {
  std::cout << RED;
  std::cout << "[WrongAnimal] destructor called" << std::endl;
  std::cout << RESET;
}
