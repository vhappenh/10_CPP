/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:02:20 by vhappenh          #+#    #+#             */
/*   Updated: 2023/08/29 15:48:18 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat& other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain();
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void	Cat::makeSound() const
{
	std::cout << "\033[1;32m" << "makes basic Cat sound" << "\033[0m" << std::endl;
}