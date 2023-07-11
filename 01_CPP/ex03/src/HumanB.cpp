/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:01:57 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/11 11:52:39 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB (std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon << std::endl;
}

void HumanB::setType(std::string type)
{
	(void) type;
}

void HumanB::setWeapon(Weapon weapon)
{
	(void) weapon;	
}

HumanB::~HumanB (void) {}