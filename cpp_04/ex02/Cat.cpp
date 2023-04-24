/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:48:41 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/24 09:13:04 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Colors.hpp"

Cat::Cat(void) : AAnimal("Cat") {
  std::cout << GREEN;
  std::cout << "[Cat] constructor called" << std::endl;
  std::cout << RESET;
  this->_brain = new Brain();
};

Cat::Cat(const Cat &other) : AAnimal(other) {
  std::cout << YELLOW;
  std::cout << "[Cat] copy constructor called" << std::endl;
  std::cout << RESET;
  this->_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other) {
  if (this != &other) {
    AAnimal::operator=(other);
    if (this->_brain != NULL) {
      delete (this->_brain);
    }
    this->_brain = new Brain(*other._brain);
  }
  return (*this);
}

Cat::~Cat(void) {
  delete this->_brain;
  std::cout << RED;
  std::cout << "[Cat] destructor called" << std::endl;
  std::cout << RESET;
}

void Cat::makeSound(void) const {
  std::cout << BLUE;
  std::cout << "[Cat] sound 🔊" << std::endl;
  std::cout << RESET;
}