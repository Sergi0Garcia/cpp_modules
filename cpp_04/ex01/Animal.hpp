/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:46:56 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/16 15:07:42 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal {
public:
  Animal(void);
  Animal(const std::string type);
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);
  virtual ~Animal(void);

  virtual void makeSound(void) const;
  std::string getType(void) const;

protected:
  std::string _type;
};

#endif