/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:58:52 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/24 11:00:39 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "Colors.hpp"

Character::Character(void) : _name("DefautlName") {
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = NULL;
  }
  std::cout << GREEN;
  std::cout << "[Character] default constructor called" << std::endl;
  std::cout << RESET;
}

Character::Character(const std::string name) : _name(name) {
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = NULL;
  }
  std::cout << GREEN;
  std::cout << "[Character] " << name << " constructor called" << std::endl;
  std::cout << RESET;
}

Character::Character(const Character &other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[Character] copy constructor called" << std::endl;
  std::cout << RESET;
}

Character &Character::operator=(const Character &other) {
  std::cout << "Character copy operator" << std::endl;
  if (this != &other) {
    this->_name = other._name;
    // deleting previous Materia
    for (int i = 0; i < 4; i++) {
      if (this->_inventory[i] != NULL) {
        delete this->_inventory[i];
      }
    }
    for (int i = 0; i < 4; i++) {
      if (other._inventory[i] != NULL) {
        // copying new materia
        this->_inventory[i] = other._inventory[i]->clone();
      }
    }
  }
  return (*this);
}

Character::~Character(void) {
  std::cout << RED;
  std::cout << "[Character] " << this->getName() << " deconstructor called"
            << std::endl;
  std::cout << RESET;
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] != NULL) {
      delete this->_inventory[i];
    }
  }
}

std::string const &Character::getName(void) const { return (this->_name); }

void Character::equip(AMateria *m) {
  if (m == NULL) {
    std::cout << RED;
    std::cout << "[Character] " << this->getName()
              << " cannot equipp NULL Materia " << std::endl;
    std::cout << RESET;
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] == NULL) {
      this->_inventory[i] = m;
      std::cout << BLUE;
      std::cout << "[Character] " << this->getName() << " equipped with "
                << m->getType() << " in slot" << i << std::endl;
      std::cout << RESET;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx > 3) {
    std::cout << RED;
    std::cout << "[Character] idx/slot out of range" << std::endl;
    std::cout << RESET;
    return;
  }
  if (this->_inventory[idx] == NULL) {
    std::cout << BLUE;
    std::cout << "[Character] " << this->getName()
              << " cant unequip, slot in inventory not found" << std::endl;
    std::cout << RESET;
  } else {
    this->_inventory[idx] = NULL;
    std::cout << BLUE;
    std::cout << "[Character] " << this->getName()
              << " sucessfully unequiped slot " << idx << " in inventory"
              << std::endl;
    std::cout << RESET;
  }
  return;
}

void Character::use(int idx, ICharacter &target) {
  if (idx > 3) {
    std::cout << RED;
    std::cout << "[Character] idx/slot out of range" << std::endl;
    std::cout << RESET;
    return;
  }
  // if (&target == NULL) {
  //   std::cout << RED;
  //   std::cout << "[Character] target is NULL" << std::endl;
  //   std::cout << RESET;
  //   return;
  // }
  if (this->_inventory[idx] == NULL) {
    std::cout << BLUE;
    std::cout << "[Character] " << this->getName()
              << " cant use Materia, slot in inventory not found" << std::endl;
    std::cout << RESET;
  } else {
    this->_inventory[idx]->use(target);
    std::cout << BLUE;
    std::cout << "[Character] " << this->getName() << " uses "
              << this->_inventory[idx]->getType() << std::endl;
    std::cout << RESET;
  }
}