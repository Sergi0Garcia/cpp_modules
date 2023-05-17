/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:30:57 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/17 10:16:02 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "iter.hpp"
#include <cctype>
#include <iostream>

void capitalize(std::string &str) {
  int len = str.length();
  for (int i = 0; i < len; i++) {
    str[i] = std::toupper(str[i]);
  }
}

void ft_tolowercase(std::string &str) {
  int len = str.length();
  for (int i = 0; i < len; i++) {
    str[i] = std::tolower(str[i]);
  }
}

void multiplier(int &num) { num = num * 2; }

template <typename T> void print_arr(std::string title, int len, T *arr) {
  std::cout << " ----- " << title << " ----- " << std::endl;
  for (int i = 0; i < len; i++) {
    std::cout << PURPLE;
    std::cout << "[" << i << "] = " << arr[i] << std::endl;
    std::cout << RESET;
  }
}

int main(void) {
  std::cout << "[Iter] Starting tests" << std::endl;

  std::string arr_str[5] = {"Frank", "James", "John", "Steve", "Dave"};
  int arr_num[5] = {2, 4, 6, 8, 10};

  print_arr("String array", 5, arr_str);
  print_arr("Number array", 5, arr_num);
  ::iter(arr_str, 5, capitalize);
  ::iter(arr_num, 5, multiplier);
  print_arr("String array", 5, arr_str);
  print_arr("Number array", 5, arr_num);
  ::iter(arr_str, 5, ft_tolowercase);
  print_arr("String array", 5, arr_str);
  // system("leaks iter");
  return (0);
}