/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:27:45 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/11 11:43:34 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Serializer.hpp"

void print_data(Data *data) {
  std::cout << PURPLE;
  std::cout << "[Data] str: " << data->str << " - address: " << &data->str
            << std::endl;
  std::cout << "[Data] num: " << data->num << " - address: " << &data->num
            << std::endl;
  std::cout << RESET;
}

int main(void) {
  Data *data;
  data = new Data;
  data->str = "Hello World";
  data->num = 7;

  Serializer serializer;
  Data *test;

  uintptr_t ptr;
  // Use serialize() on the address of the Data object
  ptr = serializer.serialize(data);
  std::cout << "[Data] ptr serialized: " << ptr << std::endl;
  // pass its return value to deserialize()
  test = serializer.deserialize(ptr);
  // Then, ensure the return value compares equal to the original pointer.
  print_data(data);
  print_data(test);
  return (0);
}