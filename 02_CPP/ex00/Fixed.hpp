/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:27:57 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/16 12:16:04 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int	_value;
	static const int _bits = 8;
public:
	Fixed(void);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);	
	~Fixed(void);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
} ;

#endif