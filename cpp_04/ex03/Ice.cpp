/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:53:56 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/18 15:03:54 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Colors.hpp"

Ice::Ice(void) : AMateria("ice") {
  std::cout << GREEN;
  std::cout << "[Ice] default constructor called" << std::endl;
  std::cout << RESET;
}

Ice::Ice(const Ice &other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[Ice] copy constructor called" << std::endl;
  std::cout << RESET;
}

Ice &Ice::operator=(const Ice &other) {
  if (this != &other) {
    this->_type = other._type;
  }
  return (*this);
}

Ice::~Ice(void) {
  std::cout << RED;
  std::cout << "[Ice] destructor called" << std::endl;
  std::cout << RESET;
}

AMateria *Ice::clone(void) const { return (new Ice(*this)); }

void Ice::use(ICharacter &target) {
  std::cout << BLUE;
  std::cout << "[Ice] * shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
  std::cout << RESET;
}
