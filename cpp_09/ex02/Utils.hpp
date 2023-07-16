/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:27:36 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/16 17:50:32 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include "Errors.hpp"
#include <iostream>

bool print_error(ERROR err);
bool valid_argc(int argc);
bool valid_argv(char **str, int argc);