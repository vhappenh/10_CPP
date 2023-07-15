/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:27:57 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/15 13:15:02 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int	_fix;
	static const int _bits = 8;
public:
	Fixed(int fix);
	Fixed(const Fixed& other);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);
} ;

#endif