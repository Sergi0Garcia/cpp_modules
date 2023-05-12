/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:30:57 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/12 11:58:39 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "array.hpp"
#include <iostream>
#include <string>

template <typename T> void print_array(std::string title, Array<T> arr) {
  std::cout << PURPLE;
  std::cout << "[Array] " << title << std::endl;
  std::cout << BLUE;
  for (unsigned int i = 0; i < arr.size(); i++) {
    std::cout << "[Array][" << i << "] = " << arr[i] << std::endl;
  }
  std::cout << RESET;
}

int main(void) {

  Array<int> test;
  Array<int> arr_int(5);
  Array<char> arr_char(5);

  for (unsigned int i = 0; i < arr_int.size(); i++) {
    arr_int[i] = i * 2;
  }
  for (unsigned int i = 0; i < arr_char.size(); i++) {
    arr_char[i] = 'a' + i;
  }
  Array<int> arr_copy(arr_int);

  print_array("test", test);
  print_array("arr_int", arr_int);
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