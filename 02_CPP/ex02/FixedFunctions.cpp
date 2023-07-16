/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedFunctions.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:33:13 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/16 19:03:27 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
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
    std::cout << other.toFloat();
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
    Fixed fixed;
   fixed.setRawBits(_value + other.getRawBits());
    return (fixed);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed fixed;
    fixed.setRawBits(_value - other.getRawBits());
    return (fixed);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed fixed;
    fixed.setRawBits(_value * other.getRawBits());
    return (fixed);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed fixed;
    fixed.setRawBits(this->_value / other.getRawBits());
    return (fixed);
}

/* increment / decrement */
// void operator++(const Fixed& other)
// {
//     const int x = other.getRawBits() + 1;
//     other.setRawBits(x);
// }

// void operator--(const Fixed& other)
// {
//     int x = other.getRawBits() - 1;
//     other.setRawBits(x);
// }