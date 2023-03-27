/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:19:19 by segarcia          #+#    #+#             */
/*   Updated: 2023/03/27 13:25:04 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <iomanip>

class Contact {
  private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;
    std::string _input(std::string str);
    std::string _trim(std::string str);

  public:
    Contact(void);
    ~Contact(void);
    void    add(void);
    bool    valid(void);
    void    short_view(int idx);
    void    large_view(void);
};

#endif