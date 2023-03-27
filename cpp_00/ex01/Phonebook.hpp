/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:58:00 by segarcia          #+#    #+#             */
/*   Updated: 2023/03/27 12:39:21 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class Phonebook {
  private:
    Contact _contacts[8];
    int     _available_idx(void);
  public:
    Phonebook(void);
    ~Phonebook(void);
    void    init_prompt(void);
    void    add_contact(void);
};

#endif