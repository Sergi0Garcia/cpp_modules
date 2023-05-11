/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:14:46 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/11 11:40:03 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Colors.hpp"

Serializer::Serializer(void) {
  std::cout << GREEN;
  std::cout << "[Serializer] constructor called" << std::endl;
  std::cout << RESET;
}

Serializer::Serializer(const Serializer &other) {
  std::cout << YELLOW;
  std::cout << "[Serializer] copy constructor called" << std::endl;
  std::cout << RESET;
  *this = other;
}

Serializer &Serializer::operator=(const Serializer &other) {
  if (this != &other) {
    *this = other;
  }
  return (*this);
}

Serializer::~Serializer(void) {
  std::cout << RED;
  std::cout << "[Serializer] destructor called" << std::endl;
  std::cout << RESET;
}

uintptr_t Serializer::serialize(Data *ptr) {
  std::cout << BLUE;
  std::cout << "[Serializer] serializing ..." << std::endl;
  std::cout << RESET;
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
  std::cout << BLUE;
  std::cout << "[Serializer] deserializing ..." << std::endl;
  std::cout << RESET;
  return (reinterpret_cast<Data *>(raw));
}