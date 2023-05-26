/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:28:27 by segarcia          #+#    #+#             */
/*   Updated: 2023/05/26 13:27:37 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

void normal_stack(void) {
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  std_stack.push(3);
  std_stack.push(4);
  std_stack.push(5);
  std::cout << std_stack.top();
}

void test_list(void) {
  std::list<int> num_list;
  num_list.push_back(5);
  num_list.push_back(17);
  num_list.pop_back();
  std::cout << "Size: " << num_list.size() << std::endl;
  num_list.push_back(3);
  num_list.push_back(5);
  num_list.push_back(737);
  num_list.push_back(0);

  std::list<int>::iterator it = num_list.begin();
  std::list<int>::iterator ite = num_list.end();
  ++it;
  --it;
  std::cout << "Printing iteration: " << std::endl;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
}

void test_mutant(void) {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << "Top: " << mstack.top() << std::endl;
  mstack.pop();
  std::cout << "Size: " << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  std::cout << "Printing iteration: " << std::endl;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}

int main(void) {
  std::cout << "TEST LIST" << std::endl << std::endl;
  test_list();
  std::cout << "TEST MUTANT" << std::endl << std::endl;
  test_mutant();
  return (0);
}