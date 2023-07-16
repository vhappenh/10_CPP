/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:27:53 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/16 14:23:55 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	this->_value = num << this->_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
	this->_value = roundf(num * (float)(1 << this->_bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	this->_value = other._value;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _value = other._value;
    }
    return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
