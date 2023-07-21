/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:41:44 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/21 14:26:45 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_hp = 100;
	this->_energy = 50;
	this->_ad = 20;
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