/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:58:44 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/06 13:09:10 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#define DB_CSV_PATH "data.csv"

int main(int argc, char **argv) {
  BitcoinExchange btc_exchange;
  if (!btc_exchange.valid_db(DB_CSV_PATH) ||
      !btc_exchange.parse_db(DB_CSV_PATH) ||
      !btc_exchange.valid_arguments(argc) ||
      !btc_exchange.valid_input_file(argv[1]))
    return (1);
  btc_exchange.execute(argv[1]);
  return (0);
}