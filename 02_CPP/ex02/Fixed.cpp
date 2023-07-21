/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:27:53 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/21 10:35:09 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_value = 0;
}

Fixed::Fixed(const int num)
{
	this->_value = num << this->_bits;
}

Fixed::Fixed(const float num)
{
	this->_value = roundf(num * (float)(1 << this->_bits));
}

Fixed::Fixed(const Fixed& other)
{
	this->_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
    {
        _value = other._value;
    }
    return *this;
}

Fixed::~Fixed(void) {}

int Fixed::getRawBits() const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
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
    return (one < two ? one : two);
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two)
{    
    return (one < two ? one : two);
}

Fixed& Fixed::max(Fixed& one, Fixed& two)
{
    return (one > two ? one : two);
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two)
{
    return (one > two ? one : two);
}
