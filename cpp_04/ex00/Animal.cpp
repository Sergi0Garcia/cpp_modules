/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:52:34 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/16 13:21:48 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Colors.hpp"

Animal::Animal() : _type("default") {
  std::cout << GREEN;
  std::cout << "[Animal] default constructor called" << std::endl;
  std::cout << RESET;
}

Animal::Animal(const std::string type) : _type(type) {
  std::cout << GREEN;
  std::cout << "[Animal] " << type << " constructor called" << std::endl;
  std::cout << RESET;
}

Animal::Animal(const Animal &other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[Animal] copy constructor called" << std::endl;
  std::cout << RESET;
}

Animal &Animal::operator=(const Animal &other) {
  if (this != &other) {
    this->_type = other._type;
  }
  return (*this);
}

void Animal::makeSound(void) const {
  std::cout << BLUE;
  std::cout << "[Animal] sound 🔊" << std::endl;
  std::cout << RESET;
}

std::string Animal::getType(void) const { return (this->_type); }

Animal::~Animal() {
  std::cout << RED;
  std::cout << "[Animal] destructor called" << std::endl;
  std::cout << RESET;
}
