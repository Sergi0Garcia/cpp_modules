/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:52:34 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/16 15:00:08 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Colors.hpp"

AAnimal::AAnimal(void) : _type("default") {
  std::cout << GREEN;
  std::cout << "[AAnimal] default constructor called" << std::endl;
  std::cout << RESET;
}

AAnimal::AAnimal(const std::string type) : _type(type) {
  std::cout << GREEN;
  std::cout << "[AAnimal] " << type << " constructor called" << std::endl;
  std::cout << RESET;
}

AAnimal::AAnimal(const AAnimal &other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[AAnimal] copy constructor called" << std::endl;
  std::cout << RESET;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
  if (this != &other) {
    this->_type = other._type;
  }
  return (*this);
}

void AAnimal::makeSound(void) const {
  std::cout << BLUE;
  std::cout << "[AAnimal] sound 🔊" << std::endl;
  std::cout << RESET;
}

std::string AAnimal::getType(void) const { return (this->_type); }

AAnimal::~AAnimal(void) {
  std::cout << RED;
  std::cout << "[AAnimal] destructor called" << std::endl;
  std::cout << RESET;
}
