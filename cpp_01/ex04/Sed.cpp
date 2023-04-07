/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:17:26 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/05 13:07:24 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include "Colors.hpp"

Sed::Sed(std::string filename, std::string s1, std::string s2): _filename(filename), _s1(s1), _s2(s2)
{
    this->_outfile = this->_filename + ".replace";
    return ;
}

Sed::~Sed(void)
{
    return ;
}

bool Sed::isValid(void) const 
{
   if (this->_filename.empty() || this->_s1.empty() || this->_s2.empty())
      return (false);
   return (true); 
}

std::string Sed::ftReplace(std::string source, std::string s1, std::string s2)
{
    if (!s1.compare(s2))
        return (source);
    size_t pos = 0;
    while ((pos = source.find(s1, pos)) != std::string::npos)
    {
        source.erase(pos, s1.length());
        source.insert(pos, s2);
        pos += s2.length();
    }
    return (source);
}

int Sed::execute(void)
{
    std::ifstream file(this->_filename);
    if (!file.is_open()) {
        std::cout << RED << "Failed to open file." << std::endl;
        return (EXIT_FAILURE);
    }
    std::string content;
    std::getline(file, content, '\0');
    if (content.empty())
    {
        std::cout << RED << "Empty file" << std::endl;
        file.close();
        return (EXIT_FAILURE);
    }
    std::ofstream outFile(this->_outfile);
    if (!outFile.is_open()) {
        std::cout << RED << "Failed to create file." << std::endl;
        file.close();
        return (EXIT_FAILURE);
    }
    outFile << this->ftReplace(content, this->_s1, this->_s2);
    while (std::getline(file, content, '\0')) {
        outFile << this->ftReplace(content, this->_s1, this->_s2);
    }
    outFile.close();    
    file.close();
    return (EXIT_SUCCESS);
}
