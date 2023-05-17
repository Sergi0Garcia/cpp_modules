/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:34:50 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/17 10:13:35 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> void iter(T *arr, int len, void (*func)(T &)) {
  if (!arr || !func)
    return;
  for (int i = 0; i < len; i++) {
    func(arr[i]);
  }
}