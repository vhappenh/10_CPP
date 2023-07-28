/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:47:11 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/28 14:56:48 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->brain = new Brain();
		this->brain = other.brain;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

std::string Dog::getType() const
{
	return (this->type);
}

void	Dog::setType(const std::string type)
{
	this->type = type;
}

void	Dog::makeSound() const
{
	std::cout << "\033[1;32m" << "makes basic Dog sound" << "\033[0m" << std::endl;
}