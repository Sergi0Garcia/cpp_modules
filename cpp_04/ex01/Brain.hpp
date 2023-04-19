/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:45:48 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/19 14:41:56 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain {
public:
  Brain(void);
  Brain(const Brain &other);
  Brain &operator=(const Brain &other);
  ~Brain(void);
  void getAddress(void) const;

private:
  std::string _ideas[100];
};
#endif