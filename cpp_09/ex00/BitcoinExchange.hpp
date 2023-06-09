/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:06:43 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/11 13:26:00 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Utils.hpp"
#include <fstream>
#include <iostream>
#include <map>

#define DB_CSV_PATH "./data/data.csv"
#pragma once

class BitcoinExchange {
private:
  std::map<std::string, double> _data;
  double getDBValue(std::string date);

public:
  BitcoinExchange();
  ~BitcoinExchange();

  bool valid_database(void);
  bool parse_database(void);
  bool valid_arguments(const int argc);
  bool valid_input_file(const char *file_path);
  bool print_value(const std::string date);
  bool execute(const char *file_path);
};