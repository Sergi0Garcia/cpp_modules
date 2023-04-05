/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:00:27 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/05 12:37:48 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"
#include "Colors.hpp"

int main(void)
{
    std::cout << PURPLE << "creating zombie in stack" << RESET << std::endl;
    Zombie zombieInStack("Zombie1");
    zombieInStack.announce();
   
    std::cout << PURPLE << "creating zombie in heap" << RESET << std::endl;
    Zombie* zombieInHeap = new Zombie("Zombie2");
    zombieInHeap->announce();

    std::cout << PURPLE << "creating zombie in heap with newZombie" << RESET << std::endl;
    Zombie* zombieInHeapFromFunction = newZombie("Zombie3");
    zombieInHeapFromFunction->announce();

    std::cout << PURPLE << "creating zombie in stack with randomChump" << RESET << std::endl;
    randomChump("Zombie4");

    delete (zombieInHeap);
    delete (zombieInHeapFromFunction);
    // system("leaks zombie");
    return (EXIT_SUCCESS);
}
