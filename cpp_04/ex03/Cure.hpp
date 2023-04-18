/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:42:24 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/18 14:48:43 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure(void);
  Cure(const Cure &other);
  Cure &operator=(const Cure &other);
  ~Cure(void);

  virtual AMateria *clone(void) const;
  virtual void use(ICharacter &target);
};

#endif