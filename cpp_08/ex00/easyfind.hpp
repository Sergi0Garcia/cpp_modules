/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:28:31 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/26 11:20:50 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>

// If value is not found in container of <int>, we return -1;
// Else we return the position of the first ocurrance.

template <typename T> int easyfind(const T &cont, const int val) {
  int idx = -1;
  try {
    typename T::const_iterator it = std::find(cont.begin(), cont.end(), val);
    if (it != cont.end())
      idx = std::distance(cont.begin(), it);
  } catch (const std::exception &) {
    return (-1);
  }
  return (idx);
}