/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:47:11 by vhappenh          #+#    #+#             */
/*   Updated: 2023/08/29 15:49:38 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal::Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain();
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void	Dog::makeSound() const
{
	std::cout << "\033[1;32m" << "makes basic Dog sound" << "\033[0m" << std::endl;
}