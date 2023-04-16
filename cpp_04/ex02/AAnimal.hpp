/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:46:56 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/16 15:07:42 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <iostream>

// An abstract class is a class that has at least one pure virtual function.
// Abstract classes cannot be instantiated, and they are used as base classes
// for other classes to inherit from and provide their own implementation for
// the pure virtual functions.
class AAnimal {
public:
  AAnimal(void);
  AAnimal(const std::string type);
  AAnimal(const AAnimal &other);
  AAnimal &operator=(const AAnimal &other);
  virtual ~AAnimal(void);

  virtual void makeSound(void) const = 0;
  std::string getType(void) const;

protected:
  std::string _type;
};

#endif