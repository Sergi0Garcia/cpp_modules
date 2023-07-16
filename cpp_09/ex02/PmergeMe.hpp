/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:54:55 by segarcia          #+#    #+#             */
/*   Updated: 2023/07/16 18:12:08 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>

class PmergeMe {
private:
  char **_input;
  int _argc;
  bool _has_straggler;
  int _straggler;
  std::vector<int> _vector;

public:
  PmergeMe(char **input, int argc);
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  bool parse_input(void);
  bool merge_insertion_sort(void);
};