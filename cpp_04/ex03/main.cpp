/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 17:00:34 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/24 11:03:16 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void moreTests(void) {
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  Character one("one");
  Character two("two");

  AMateria *tmp;
  tmp = src->createMateria("ice");
  one.equip(tmp);
  tmp = src->createMateria("cure");
  one.equip(tmp);
  tmp = src->createMateria("ice");
  two.equip(tmp);

  std::cout << std::endl;
  std::cout << std::endl;
  two = one;

  std::cout << std::endl;
  std::cout << std::endl;
  one.use(5, two);

  std::cout << std::endl;
  std::cout << std::endl;
  delete src;
  // system("leaks ex03");
}

int main(void) {
  // More tests
  // moreTests();

  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter *me = new Character("me");

  AMateria *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter *bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;
  // system("leaks ex03");
  return (0);
}