/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:58:44 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/11 12:50:45 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
  BitcoinExchange btc_exchange;
  if (!btc_exchange.valid_database() || !btc_exchange.parse_database() ||
      !btc_exchange.valid_arguments(argc) ||
      !btc_exchange.valid_input_file(argv[1]))
    return (1);
  btc_exchange.execute(argv[1]);
  return (0);
}
