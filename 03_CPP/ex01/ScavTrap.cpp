/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:41:44 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/21 13:44:28 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name, int hp, int ad, int energy)
{
	this->_name = name;
	this->_hp = hp;
	this->_ad = ad;
	this->_energy = energy;
	std::cout << "ScavTrap Constructor called!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Deconstructor called!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name
		<< " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energy > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_ad << " points of damage!" << std::endl;
		this->_energy--;
	}
	else
		std::cout << "ScavTrap " << this->_name << " can't attack. No energy left!" << std::endl;
}