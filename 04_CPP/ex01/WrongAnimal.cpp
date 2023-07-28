/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:28:27 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/28 14:18:13 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->type = "default";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::setType(const std::string type)
{
	this->type = type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "\033[1;31m" << "makes basic WrongAnimal sound" << "\033[0m" << std::endl;
}