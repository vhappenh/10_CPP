/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:02:20 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/28 14:56:57 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->brain = new Brain();
		this->brain = other.brain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

std::string Cat::getType() const
{
	return (this->type);
}

void	Cat::setType(const std::string type)
{
	this->type = type;
}

void	Cat::makeSound() const
{
	std::cout << "\033[1;32m" << "makes basic Cat sound" << "\033[0m" << std::endl;
}