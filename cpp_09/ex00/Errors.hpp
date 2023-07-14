/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:59:05 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/14 09:57:11 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
enum ERROR {
  ERROR_ARGC,
  DB_FILE,
  DB_EMPTY_FILE,
  DB_READ_ACCESS,
  DB_WRONG_HEADERS,
  DB_COMMA_SEPARATOR,
  DB_DATE_FORMAT,
  DB_PRICE_VALUE,
  DB_DELIMETER_NOT_FOUND,
  INPUT_NOT_FOUND,
  INPUT_EMPTY_FILE,
  INPUT_READ_ACCESS,
  INPUT_WRONG_HEADERS,
  INPUT_VALUE_TOO_BIG,
  INPUT_NEGATIVE_NUMBER,
  INPUT_DATE_FORMAT,
  OP_DB_VALUE,
  UNKNOWN_ERROR
};