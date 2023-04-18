/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:53:09 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/18 14:53:48 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice(void);
  Ice(const Ice &other);
  Ice &operator=(const Ice &other);
  ~Ice(void);

  virtual AMateria *clone(void) const;
  virtual void use(ICharacter &target);
};

#endif