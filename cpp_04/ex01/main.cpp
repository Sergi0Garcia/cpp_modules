/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 07:51:33 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/19 14:47:40 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

#define array_size 5

// Check for Deep Copy
void tester(void) {
  Cat cat;
  Cat newCat(cat);
  Cat differentCat;

  differentCat = cat;

  std::cout << "Original cat: " << cat.getType() << " - Address: " << &cat
            << std::endl;
  std::cout << "New cat: " << newCat.getType() << " - Address: " << &newCat
            << std::endl;
  std::cout << "Different cat: " << differentCat.getType()
            << " - Address: " << &differentCat << std::endl;

  std::cout << std::endl;
  Dog dog;
  std::cout << "starting with new dog" << std::endl;
  Dog newDog(dog);
  std::cout << "ending with new dog" << std::endl;
  Dog differentDog;

  differentDog = dog;

  std::cout << "Original dog: " << dog.getType() << " - Address: " << &dog
            << std::endl;
  std::cout << "New dog: " << newDog.getType() << " - Address: " << &newDog
            << std::endl;
  std::cout << "Different dog: " << differentDog.getType()
            << " - Address: " << &differentDog << std::endl;

  std::cout << std::endl;

  system("leaks ex01");
}

int main(void) {

  // Testing for deep copies
  tester();
  return (1);

  const Animal *j = new Dog();
  const Animal *i = new Cat();

  delete j; // should not create a leak
  delete i;

  // creating classes
  const Animal *animals[array_size];
  for (int i = 0; i < array_size; i++) {
    if (i % 2 == 0)
      animals[i] = new Dog();
    else
      animals[i] = new Cat();
  }

  // Deleting classes
  for (int i = 0; i < array_size; i++) {
    delete animals[i];
  }
  // system("leaks ex01");
  return (0);
}