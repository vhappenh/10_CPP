/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:28:22 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/28 14:16:57 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

std::string WrongCat::getType() const
{
	return (this->type);
}

void	WrongCat::setType(const std::string type)
{
	this->type = type;
}

void	WrongCat::makeSound() const
{
	std::cout << "\033[1;31m" << "makes basic WrongCat sound" << "\033[0m" << std::endl;
}