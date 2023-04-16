/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:32:51 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/16 16:56:02 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include "Colors.hpp"

Dog::Dog(void) : Animal("Dog") {
  std::cout << GREEN;
  std::cout << "[Dog] constructor called" << std::endl;
  std::cout << RESET;
  this->_brain = new Brain();
};

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << YELLOW;
  std::cout << "[Dog] copy constructor called" << std::endl;
  std::cout << RESET;
  this->_brain = new Brain(*other._brain);
  *this = other;
}

Dog &Dog::operator=(const Dog &other) {
  if (this != &other) {
    Animal::operator=(other);
    if (this->_brain != NULL) {
      delete (this->_brain);
    }
    this->_brain = new Brain(*other._brain);
  }
  return (*this);
}

Dog::~Dog(void) {
  delete this->_brain;
  std::cout << RED;
  std::cout << "[Dog] destructor called" << std::endl;
  std::cout << RESET;
}

void Dog::makeSound(void) const {
  std::cout << BLUE;
  std::cout << "[Dog] sound 🔊" << std::endl;
  std::cout << RESET;
}