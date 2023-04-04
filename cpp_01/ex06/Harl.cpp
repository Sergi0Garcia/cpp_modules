/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:47:10 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/04 14:49:33 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include "Colors.hpp"

Harl::Harl(void)
{
    return ;
}

Harl::~Harl(void)
{
    return ;
}

void Harl::debug(void)
{
    std::cout << CURSIVE << PURPLE;
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
    std::cout << RESET << std::endl;
    return ;
}

void Harl::info(void)
{
    std::cout << CURSIVE << BLUE;
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
    std::cout << RESET << std::endl;
    return ;
}

void Harl::warning(void)
{
    std::cout << CURSIVE << YELLOW;
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
    std::cout << RESET << std::endl;
    return ;
}

void Harl::error(void)
{
    std::cout << CURSIVE << RED;
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.";
    std::cout << RESET << std::endl;
    return ;
}

void Harl::complain(std:: string level) {
    int check = -1;
    t_harl  answers[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (!levels[i].compare(level))
        {
            check = i;
            break;
        }
    }
    switch (check)
    {
    case 0:
        for (int i = 0; i < 4; i++){(this->*answers[i])();std::cout<<std::endl;}
        break;
    case 1:
        for (int i = 1; i < 4; i++){(this->*answers[i])();std::cout<<std::endl;}
        break;
    case 2:
        for (int i = 2; i < 4; i++){(this->*answers[i])();std::cout<<std::endl;}
        break;
    case 3:
        for (int i = 3; i < 4; i++){(this->*answers[i])();std::cout<<std::endl;}
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
    return ; 
}