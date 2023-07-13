/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:06:43 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/13 15:38:40 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include "Utils.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#define DB_CSV_PATH "./data/data.csv"

class BitcoinExchange {
private:
  std::map<std::string, double> _data;
  double getDBValue(std::string date);

public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  bool valid_database(void);
  bool parse_database(void);
  bool valid_arguments(const int argc);
  bool valid_input_file(const char *file_path);
  bool execute(const char *file_path);
};
