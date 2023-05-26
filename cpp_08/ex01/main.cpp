/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:28:27 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/26 13:26:21 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Span.hpp"
#include <vector>

int example(void) {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  return 0;
}

void test(void) {
  Span span(2);
  span.addNumber(10);
  span.addNumber(20);

  std::vector<int> randomArr = span.generateRandom(2);
  span.addNumbers(randomArr);

  std::list<int> num_list;
  num_list.push_back(424242);
  num_list.push_back(474747);

  span.addNumbers(num_list);
  span.printArr();

  std::cout << "shortest span: " << span.shortestSpan() << std::endl;
  std::cout << "longest span: " << span.longestSpan() << std::endl;
  try {
    Span tmp(1);
    tmp.addNumber(10);
    tmp.addNumber(10);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Span tmp(1);
    tmp.addNumber(10);
    std::cout << "shortest span: " << std::endl;
    std::cout << tmp.shortestSpan();
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

int main(void) {
  example();
  // test();
  // system("leaks span");
  return (0);
}