/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:29:20 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/05 12:39:17 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    const int iterations = 5;
    Zombie* horde;
    horde = zombieHorde(iterations, "Jhon");
    for (int i = 0; i < iterations; i++)
        horde[i].announce();
    delete [] horde;
    // system("leaks horde");
    return (EXIT_SUCCESS);
}