/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:30:57 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/17 10:20:08 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "array.hpp"
#include <iostream>
#include <string>

template <typename T> void print_array(std::string title, Array<T> arr) {
  std::cout << PURPLE;
  std::cout << "[Array] " << title << " - " << &arr << std::endl;
  std::cout << BLUE;
  for (unsigned int i = 0; i < arr.size(); i++) {
    std::cout << "[Array][" << i << "] = " << arr[i] << std::endl;
  }
  std::cout << RESET;
}

int main(void) {

  // Construction with no parameter: Creates an empty array.
  Array<int> test;
  // Construction with an unsigned int n as a parameter: Creates an array of n
  // elements initialized by default.
  Array<int> arr_int(5);
  std::cout << "arr_int size: " << arr_int.size() << std::endl;
  Array<char> arr_char(5);

  for (unsigned int i = 0; i < arr_int.size(); i++) {
    arr_int[i] = i * 2;
  }
  for (unsigned int i = 0; i < arr_char.size(); i++) {
    arr_char[i] = 'a' + i;
  }

  // Construction by copy and assignment operator. In both cases, modifying
  // either the original array or its copy after copying musn’t affect the other
  Array<int> arr_copy(arr_int);
  Array<int> arr_assignment;

  arr_assignment = arr_int;
  for (unsigned int i = 0; i < arr_assignment.size(); i++) {
    arr_assignment[i] = arr_assignment[i] + 1;
  }

  print_array("test", test);
  print_array("arr_int", arr_int);
  print_array("arr_assignment", arr_assignment);
  print_array("arr_copy", arr_copy);
  print_array("arr_char", arr_char);

  try {
    std::cout << "[Array] Reading OFB: " << std::endl
              << arr_int[10] << std::endl;
  } catch (const std::exception &e) {
    std::cout << RED << "[Array] ";
    std::cout << e.what() << std::endl;
    std::cout << RESET;
  }
  // system("leaks array");
  return (0);
}