/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 07:51:33 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/24 09:15:39 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

#define array_size 5

// Check for Deep Copy
void tester(void) {
  std::cout << std::endl;
  Dog dog;
  Dog newDog(dog);
  Dog differentDog;

  differentDog = dog;
  std::cout << "Original dog: " << dog.getType() << " - Address: " << &dog
            << std::endl;
  std::cout << "New dog: " << newDog.getType() << " - Address: " << &newDog
            << std::endl;
  std::cout << "Different dog: " << differentDog.getType()
            << " - Address: " << &differentDog << std::endl;

  std::cout << std::endl;

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

  // system("leaks ex01");
}

int main(void) {

  // Testing for deep copies
  //  tester();

  const AAnimal *j = new Dog();
  const AAnimal *i = new Cat();

  // AAnimal animal; // cannot define - AAnimal is an abstract class

  delete j; // should not create a leak
  delete i;

  // creating classes
  const AAnimal *animals[array_size];
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
  // system("leaks ex02");
  return (0);
}