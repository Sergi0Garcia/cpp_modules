/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:27:36 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/17 11:37:02 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include "Errors.hpp"
#include <ctime>
#include <iostream>

bool print_error(ERROR err);
bool valid_argc(int argc);
bool valid_argv(char **str, int argc);
void print_time_diff(clock_t start, clock_t end);