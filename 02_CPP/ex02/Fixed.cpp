/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:27:53 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/20 17:48:30 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_value = 0;
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	this->_value = num << this->_bits;
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
	this->_value = roundf(num * (float)(1 << this->_bits));
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	this->_value = other._value;
	//std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _value = other._value;
    }
    return *this;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
   //std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_value) / (float)(1 << this->_bits);
}

int	Fixed::toInt(void) const
{
	return ((int)this->_value >> this->_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
    os << other.toFloat();
    return os;
}

/* comparison operators */
bool Fixed::operator>(const Fixed& other) const
{
    return (_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (_value < other._value);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (_value <= other._value);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (_value != other._value);
}

/* arithmetic operators */
Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed fixed(this->toFloat() + other.toFloat());
    return (fixed);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed fixed(this->toFloat() - other.toFloat());
    return (fixed);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed fixed(this->toFloat() * other.toFloat());
    return (fixed);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed fixed(this->toFloat() / other.toFloat());
    return (fixed);
}

/* increment / decrement */
Fixed Fixed::operator++(int)
{
    Fixed fixed(*this);
    this->setRawBits((this->getRawBits()) + 1);
    return (fixed);
}

Fixed Fixed::operator--(int)
{
    Fixed fixed(*this);
    this->setRawBits((this->getRawBits()) - 1);
    return (fixed);
}

Fixed Fixed::operator++()
{
    this->setRawBits(getRawBits() + 1);
    return (*this);
}

Fixed Fixed::operator--()
{
    this->setRawBits(getRawBits() - 1);
    return (*this);
}

Fixed& Fixed::min(Fixed& one, Fixed& two)
{
    if (one < two)
        return (one);
    else
        return (two);
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two)
{    
    if (one < two)
        return (one);
    else
        return (two);
}

Fixed& Fixed::max(Fixed& one, Fixed& two)
{
    if (one > two)
        return (one);
    else
        return (two);
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two)
{
    if (one > two)
        return (one);
    else
        return (two);
}
