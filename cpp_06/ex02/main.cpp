/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:18:02 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/11 12:34:54 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Types.hpp"

int main(void) {
  for (int i = 0; i < 10; i++) {
    Base *tmp;
    tmp = generate();
    std::cout << "[Types] iteration: " << i << std::endl;
    identify(tmp);
    identify(*tmp);
    delete tmp;
  }
  return (0);
}