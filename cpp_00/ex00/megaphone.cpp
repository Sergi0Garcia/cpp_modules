/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:27:14 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/04 14:20:57 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int i = 0; int j = 0; char c_upper = '\0';
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				c_upper = std::toupper(argv[i][j]);
				std::cout << c_upper;
				j++;
			}
			if (argv[i + 1])
				std::cout << " ";
			i++;
		}
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
