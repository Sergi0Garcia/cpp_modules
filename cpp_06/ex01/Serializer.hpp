/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:08:32 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/16 12:50:09 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <cstdint>
#include <iostream>

typedef struct Data {
  std::string str;
  int num;
} Data;

class Serializer {
public:
  Serializer();
  Serializer(const Serializer &other);
  Serializer &operator=(const Serializer &other);
  ~Serializer();

  uintptr_t serialize(Data *ptr);
  Data *deserialize(uintptr_t raw);
};

#endif