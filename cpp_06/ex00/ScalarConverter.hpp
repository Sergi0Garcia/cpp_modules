/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:58:26 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/08 13:32:36 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>

class ScalarConverter {
public:
  ScalarConverter(const std::string &input);
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();

private:
  std::string _input;
  unsigned char _char;
  int _int;
  float _float;
  double _double;

  void convert(void);

  bool is_char(void) const;
  bool is_int(void) const;
  bool is_float(void) const;
};

#endif