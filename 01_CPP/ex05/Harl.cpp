/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:55:13 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/14 11:38:59 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl (void) {}

void Harl::_debug(void)
{
    std::cout << "I'm debugging my friend. Please dnd!" << std::endl;
}

void Harl::_info(void)
{
    std::cout << "These aren't the infos that you are looking for." << std::endl;
}

void Harl::_warning(void)
{
    std::cout << "Warning: Objects in the mirror are closer than they appear." << std::endl;
}

void Harl::_error(void)
{
    
    std::cout << "I'm sorry, Dave. I'm afraid I can't do that." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string arr[5] = {"debug", "info", "warning", "error"};
    void (Harl::*teletubbies[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
    
    for (int i = 0; i < 4; i++)
    {
        if (level == arr[i])
            (this->*teletubbies[i])();
    }
}
Harl::~Harl (void) {}