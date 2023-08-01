/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:58:44 by segarcia          #+#    #+#             */
/*   Updated: 2023/08/01 11:46:51 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Utils.hpp"

int main(int argc, char **argv) {
  if (!valid_argc(argc) || !valid_argv(argv, argc))
    return (1);
  PmergeMe merger(argv, argc);
  if (!merger.init())
    return (1);
  if (!merger.sort_both())
    return (1);
  // system("leaks PmergeMe");
  return (0);
}
