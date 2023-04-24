/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:28:43 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/24 10:58:42 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Colors.hpp"

MateriaSource::MateriaSource(void) {
  for (int i = 0; i < 4; i++) {
    this->_materias[i] = NULL;
  }
  std::cout << GREEN;
  std::cout << "[MateriaSource] default constructor called" << std::endl;
  std::cout << RESET;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[MateriaSource] copy constructor called" << std::endl;
  std::cout << RESET;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  if (this != &other) {
    for (int i = 0; i < 4; i++) {
      this->_materias[i] = other._materias[i];
    }
  }
  return (*this);
}

MateriaSource::~MateriaSource(void) {
  std::cout << RED;
  std::cout << "[MateriaSource] destructor called" << std::endl;
  std::cout << RESET;
  for (int i = 0; i < 4; i++) {
    if (this->_materias[i] != NULL)
      delete this->_materias[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  for (int i = 0; i < 4; i++) {
    if (this->_materias[i] == NULL) {
      this->_materias[i] = m;
      std::cout << BLUE;
      std::cout << "[MateriaSource] materia " << m->getType()
                << " learned successfuly" << std::endl;
      std::cout << RESET;
      return;
    }
  }
  std::cout << BLUE;
  std::cout << "[MateriaSource] no space left to learn Materia" << std::endl;
  std::cout << RESET;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  for (int i = 0; i < 4; i++) {
    if (this->_materias[i] && this->_materias[i]->getType() == type) {
      return this->_materias[i]->clone();
    }
  }
  return NULL;
}