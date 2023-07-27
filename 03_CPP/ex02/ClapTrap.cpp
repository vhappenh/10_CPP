/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:40:09 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/27 13:02:18 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hp = 10;
	this->_energy = 10;
	this->_ad = 0;
	std::cout << "ClapTrap Constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_energy = other._energy;
		this->_ad = other._ad;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_ad << " points of damage!" << std::endl;
		this->_energy--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't attack. No energy left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hp -= amount;
	if (this->_hp <= 0)
	std::cout << "ClapTrap " << this->_name << "'s health was decreased by "
		<< amount << " HP!" << std::endl;
	std::cout << "ClapTrap " << this->_name << " has now "
		<< this->_hp << " HP left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy > 0)
	{
		this->_hp += amount;
		std::cout << "ClapTrap " << this->_name << "'s health was restored by "
			<< amount << " HP!" << std::endl;
		std::cout << "ClapTrap " << this->_name << " has now "
			<< this->_hp << " HP left!" << std::endl;
		this->_energy--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't repair. No energy left!" << std::endl;
}