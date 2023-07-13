/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:58:44 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/13 13:50:02 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "utils.cpp"
#include <iostream>

int main(int argc, char **argv) {
  if (!valid_argc(argc))
    return (1);
  std::string input = static_cast<std::string>(argv[1]);
  if (!valid_input(input))
    return (1);
  RPN rpn(input);
  if (!rpn.run())
    return (1);
  return (0);
}