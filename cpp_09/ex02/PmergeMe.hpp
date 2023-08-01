/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:54:55 by segarcia          #+#    #+#             */
/*   Updated: 2023/08/01 11:56:44 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <deque>
#include <vector>

class PmergeMe {
private:
  char **_input;
  int _argc;
  bool _has_straggler;
  int _straggler;
  std::vector<int> _vector;
  std::vector<int> _vjacob;
  std::deque<int> _deque;
  std::deque<int> _djacob;
  std::vector<int> _sorted_vector;
  std::deque<int> _sorted_deque;

public:
  PmergeMe(char **input, int argc);
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  bool init(void);
  bool parse_input(void);
  bool sort_vector(void);
  bool sort_deque(void);
  bool sort_both(void);
};

// https://ebang.tistory.com/104
// https://github.com/decidedlyso/merge-insertion-sort