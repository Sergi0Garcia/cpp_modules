/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:06:43 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/06 11:22:47 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include <iostream>
#include <map>
#include <stdio.h>

class BitcoinExchange {
private:
  std::map<std::string, double> _data;

public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  bool valid_args(const int argc);
  bool valid_file(const char *file_path);
  bool parse_db(const char *file_path);
  bool parse_input(const char *file_path);
  bool print_value(const std::string date);
};