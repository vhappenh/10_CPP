/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:19:48 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/21 14:28:42 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_hp = 100;
	this->_energy = 100;
	this->_ad = 30;
	std::cout << "FragTrap Constructor called!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Deconstructor called!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name
		<< " gives you a high five." << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_energy > 0)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_ad << " points of damage!" << std::endl;
		this->_energy--;
	}
	else
		std::cout << "FragTrap " << this->_name << " can't attack. No energy left!" << std::endl;
}