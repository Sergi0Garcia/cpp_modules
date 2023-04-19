/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:46:27 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/19 09:35:41 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Colors.hpp"

Cure::Cure(void) : AMateria("cure") {
  std::cout << GREEN;
  std::cout << "[Cure] default constructor called" << std::endl;
  std::cout << RESET;
}

Cure::Cure(const Cure &other) : AMateria(other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[Cure] copy constructor called" << std::endl;
  std::cout << RESET;
}

Cure &Cure::operator=(const Cure &other) {
  if (this != &other) {
    this->_type = other._type;
  }
  return (*this);
}

Cure::~Cure(void) {
  std::cout << RED;
  std::cout << "[Cure] destructor called" << std::endl;
  std::cout << RESET;
}

AMateria *Cure::clone(void) const { return (new Cure(*this)); }

void Cure::use(ICharacter &target) {
  std::cout << BLUE;
  std::cout << "[Cure] * heals " << target.getName() << "'s wounds *"
            << std::endl;
  std::cout << RESET;
}
