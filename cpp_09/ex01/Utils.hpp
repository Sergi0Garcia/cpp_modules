/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:27:36 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/13 14:28:48 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Colors.hpp"
#include "Errors.hpp"
#include <iostream>

bool print_error(ERROR err);
bool valid_argc(int argc);
bool valid_input(std::string str);
std::string trimWhitespace(const std::string str);
bool is_empty_str(std::string str);