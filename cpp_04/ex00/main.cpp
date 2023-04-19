/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 07:51:33 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/19 09:52:40 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {

  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << meta->getType() << " " << std::endl;
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;

  meta->makeSound(); // will output the animal sound!
  j->makeSound();    // will output the dog sound!
  i->makeSound();    // will output the cat sound!

  delete meta;
  delete j;
  delete i;

  // Wrong Class
  std::cout << std::endl << std::endl;

  const WrongAnimal *beta = new WrongAnimal();
  const WrongAnimal *ix = new WrongCat();

  std::cout << beta->getType() << " " << std::endl;
  std::cout << ix->getType() << " " << std::endl;

  beta->makeSound(); // will output the wrong animal sound!
  ix->makeSound();   // will output the wrong animal sound!

  delete beta; // Destructor of base class Wrong Animal!
  delete ix; // WILL ONLY DESTRUCTOR WRONGANIMAL AND NOT WRONG CAT BECUASE THERE
             // IS NO VIRTUAL IN BASE CLASS
  // system("leaks ex00");
  return (0);
}