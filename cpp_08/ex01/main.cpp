/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:28:27 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/23 11:54:35 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Span.hpp"
#include <vector>

int main(void) {
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
  std::cout << "longest span: " << span.longestSpann() << std::endl;
}