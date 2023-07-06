/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:58:44 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/06 11:22:19 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
  BitcoinExchange btc_exchange;

  if (!btc_exchange.valid_args(argc))
    return (1);
  if (!btc_exchange.valid_file(argv[1]))
    return (1);
  btc_exchange.parse_db(argv[1]);
  btc_exchange.print_value("2019-08-15");
  return (0);
}