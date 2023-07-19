/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:27:57 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/19 11:58:47 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <tgmath.h>

class Fixed
{
private:
	int	_value;
	static const int _bits = 8;
public:
	/* constructor / deconstructor */
	Fixed(void);
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);	
	~Fixed(void);
	
	/* functions */
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
	float 	toFloat(void) const;
	int		toInt(void) const;

	/* comparison operators */
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	/* arithmetic operators */
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	/* increment / decrement */
	Fixed operator++(int);
	Fixed operator--(int);
	Fixed operator++();
	Fixed operator--();

	/* min / max */
	static Fixed& min(Fixed& one, Fixed& two);
	static const Fixed& min(const Fixed& one, const Fixed& two);
	static Fixed& max(Fixed& one, Fixed& two);
	static const Fixed& max(const Fixed& one, const Fixed& two);
} ;

std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif