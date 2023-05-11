/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:44:52 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/11 12:59:21 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T> T min(T &a, T &b) {
  if (a < b)
    return (a);
  else if (b < a)
    return (b);
  else if (a == b)
    return (b);
  return (b);
}

template <typename T> T max(T &a, T &b) {
  if (a > b)
    return (a);
  else if (b > a)
    return (b);
  else if (a == b)
    return (b);
  return (b);
}