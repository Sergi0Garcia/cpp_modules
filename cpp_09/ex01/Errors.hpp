/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:59:05 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/13 13:46:50 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
enum ERROR {
  INVALID_ARGC,
  EMPTY_STRING,
  INVALID_CHAR,
  STACK_SIZE,
  MISSING_OPERATOR,
  MISSING_OPERATOR_MANY_NUMBERS,
  INT_OUT_OF_RANGE
};