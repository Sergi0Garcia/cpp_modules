/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:28:27 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/26 11:21:56 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) {
  std::vector<int> num_vector;
  num_vector.push_back(10);
  num_vector.push_back(20);
  num_vector.push_back(30);

  const std::vector<int> const_num_vector(num_vector);
  std::cout << "num_vector[0] = " << num_vector[0] << std::endl;
  std::cout << "num_vector[1] = " << num_vector[1] << std::endl;
  std::cout << "num_vector[2] = " << num_vector[2] << std::endl;

  std::cout << "const_num_vector[0] = " << const_num_vector[0] << std::endl;
  std::cout << "const_num_vector[1] = " << const_num_vector[1] << std::endl;
  std::cout << "const_num_vector[2] = " << const_num_vector[2] << std::endl;

  std::cout << "value 10 is in idx: " << easyfind(num_vector, 10) << std::endl;
  std::cout << "value 20 is in idx: " << easyfind(num_vector, 20) << std::endl;
  std::cout << "value 30 is in idx: " << easyfind(const_num_vector, 30)
            << std::endl;
  std::cout << "value 40 is in idx: " << easyfind(const_num_vector, 40)
            << std::endl;

  std::list<int> num_list;
  num_list.push_back(100);
  num_list.push_back(200);
  num_list.push_back(300);
  std::cout << "value 100 is in idx: " << easyfind(num_list, 100) << std::endl;

  std::set<int> num_set;
  num_set.insert(90);
  num_set.insert(80);
  num_set.insert(70);

  std::cout << "num_set: " << *num_set.begin() << std::endl;
  std::set<int>::iterator it = num_set.begin();
  it++;
  // Next not available in c++98
  // std::cout << "num_set: " << *std::next(num_set.begin()) << std::endl;
  // std::cout << "num_set: " << *num_set.begin() << std::endl;
  std::cout << "num_set: " << *it << std::endl;

  std::cout << "value 80 is in idx: " << easyfind(num_set, 80) << std::endl;
  return (1);
}