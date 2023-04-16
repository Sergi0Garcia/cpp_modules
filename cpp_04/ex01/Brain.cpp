/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:55:13 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/16 16:12:00 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Colors.hpp"

Brain::Brain(void) {
  std::cout << GREEN;
  std::cout << "[Brain] constructor called" << std::endl;
  std::cout << RESET;
};

Brain::Brain(const Brain &other) {
  *this = other;
  std::cout << YELLOW;
  std::cout << "[Brain] copy constructor called" << std::endl;
  std::cout << RESET;
}

Brain &Brain::operator=(const Brain &other) {
  if (this != &other) {
    for (int i = 0; i < 100; i++) {
      this->_ideas[i] = other._ideas[i];
    }
  }
  return (*this);
}

Brain::~Brain(void) {
  std::cout << RED;
  std::cout << "[Brain] destructor called" << std::endl;
  std::cout << RESET;
}