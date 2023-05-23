/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:32:55 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/23 12:34:51 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;

  iterator begin() { return this->c.begin(); }

  iterator end() { return this->c.end(); }

  const_iterator begin() const { return this->c.begin(); }

  const_iterator end() const { return this->c.end(); }
};