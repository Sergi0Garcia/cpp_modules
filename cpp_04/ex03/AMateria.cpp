/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:19:47 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/18 14:39:13 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Colors.hpp"
#include <iostream>

AMateria::AMateria(void) : _type("defaultType") {
  std::cout << GREEN;
  std::cout << "[AMateria] default constructor called" << std::endl;
  std::cout << RESET;
}

AMateria::AMateria(std::string const &type) : _type(type) {
  std::cout << GREEN;
  std::cout << "[AMateria] " << type << " constructor called" << std::endl;
  std::cout << RESET;
}

AMateria::AMateria(const AMateria &other) {
  std::cout << YELLOW;
  std::cout << "[AMateria] copy constructor called" << std::endl;
  std::cout << RESET;
  *this = other;
}

AMateria::~AMateria(void) {
  std::cout << RED;
  std::cout << "[AMateria] destructor called" << std::endl;
  std::cout << RESET;
}

std::string const &AMateria::getType(void) const { return (this->_type); }

AMateria *AMateria::clone(void) const { return (AMateria *)this; }

void AMateria::use(ICharacter &target) {
  std::cout << BLUE;
  std::cout << "[AMateria] " << this->_type << "used by" << target.getName()
            << std::endl;
  std::cout << RESET;
}