/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:58:00 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/03 12:48:03 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
  private:
    Contact _contacts[8];
    int     _available_idx(void);
    int     _input(std::string str);
    
  public:
    PhoneBook(void);
    ~PhoneBook(void);
    void    init_prompt(void);
    void    add_contact(void);
    int     display_contacts(void);
    void    view_full_info(void);
};

#endif