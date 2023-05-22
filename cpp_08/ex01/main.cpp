/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:28:27 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/22 13:35:51 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Span.hpp"

int main(void) {
  Span span(5);
  span.addNumber(6);
  span.addNumber(3);
  span.addNumber(17);
  span.addNumber(9);
  span.addNumber(11);

  std::cout << "shortest span: " << span.shortestSpan() << std::endl;
  std::cout << "longest span: " << span.longestSpann() << std::endl;
}