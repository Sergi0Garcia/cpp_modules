/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:48:41 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/16 13:29:15 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include "Colors.hpp"

Cat::Cat(void) : Animal("Cat") {
  std::cout << GREEN;
  std::cout << "[Cat] constructor called" << std::endl;
  std::cout << RESET;
};

Cat::Cat(const Cat &other) : Animal(other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[Cat] copy constructor called" << std::endl;
  std::cout << RESET;
}

Cat &Cat::operator=(const Cat &other) {
  if (this != &other) {
    Animal::operator=(other);
  }
  return (*this);
}

Cat::~Cat(void) {
  std::cout << RED;
  std::cout << "[Cat] destructor called" << std::endl;
  std::cout << RESET;
}

void Cat::makeSound(void) const {
  std::cout << BLUE;
  std::cout << "[Cat] sound 🔊" << std::endl;
  std::cout << RESET;
}