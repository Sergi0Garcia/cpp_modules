/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:07:12 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/17 02:11:39 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> class Array {
private:
  T *_arr;
  unsigned int _len;

public:
  Array(void) : _arr(new T[0]), _len(0){};
  Array(unsigned int n) : _arr(new T[n]), _len(n){};
  Array(const Array &other) : _arr(new T[other._len]), _len(other._len) {
    for (unsigned int i = 0; i < _len; i++) {
      _arr[i] = other._arr[i];
    }
  }
  Array &operator=(const Array &other) {
    if (this != &other) {
      delete[] _arr;
      _len = other.size();
      _arr = new T[_len];
      for (unsigned int i = 0; i < _len; i++) {
        _arr[i] = other._arr[i];
      }
    }
    return (*this);
  }

  ~Array(void) { delete[] _arr; }

  unsigned int size(void) const { return (_len); }

  T &operator[](unsigned int i) const {
    if (i > _len)
      throw Array::exception();
    return (_arr[i]);
  }

  class exception : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Error: index out of bounds";
    }
  };
};