/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:58:24 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/13 15:40:38 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Errors.hpp"
#include <sstream>

template <typename T> std::string to_string(const T &value) {
  std::stringstream ss;
  ss << value;
  return ss.str();
}

bool print_error(ERROR err);
bool is_empty_file(std::ifstream &pFile);
int countRepetitions(const std::string &str, char target);
int custom_stoi(const std::string &str);
double customStod(const std::string &str);
std::string trimWhitespace(const std::string &word);
bool validateDate(std::string str);
bool validateValue(std::string str);
int getYear(std::string str);
int getMonth(std::string str);
std::string getPreviousDay(int year, int month, int day);
int getDay(std::string str);