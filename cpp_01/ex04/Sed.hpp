/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:15:15 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/05 10:55:48 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP
#include <iostream>
#include <string>
#include <fstream>

class Sed {
private:
    std::string _filename;
    std::string _outfile;
    std::string _s1;
    std::string _s2;
    std::string ftReplace(std::string source, std::string s1, std::string s2);
public:
    Sed(std::string filename, std::string s1, std::string s2);
    ~Sed(void);
    bool isValid(void) const;
    int execute(void);
};
#endif