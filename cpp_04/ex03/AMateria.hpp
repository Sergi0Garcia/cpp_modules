/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 17:04:34 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/17 14:00:43 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include "ICharacter.hpp"
#include <iostream>

#pragma once
class ICharacter;

class AMateria {
private:
  std::string _type;

public:
  AMateria(void);
  AMateria(std::string const &type);
  AMateria(const AMateria &other);
  virtual ~AMateria(void);

  std::string const &getType() const; // Returns the materia type
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif