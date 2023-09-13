/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:49:00 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/13 15:09:36 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter default constructor called!" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	std::cout << "ScalarConverter copy constructor called!" << std::endl;
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	std::cout << "ScalarConverter copy assignment operator called!" << std::endl;
	(void) other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructor called!" << std::endl;
}

void ScalarConverter::convert(std::string input) {
	double	n = strtod(input.c_str(), NULL);

	// printing char
	if (n <= std::numeric_limits<unsigned char>::max() && n >= std::numeric_limits<unsigned char>::min())
		(std::isprint(n)) ? (std::cout << "char  : '" << static_cast<unsigned char>(n) << "'" << std::endl) : (std::cout << "char  : non printable" << std::endl); 
	else
		std::cout << "char  : impossible" << std::endl;
	
	// printing int
	if (n <= std::numeric_limits<int>::max() && n >= std::numeric_limits<int>::min())
		std::cout << "int   : " << static_cast<int>(n) << std::endl;
	else
		std::cout << "int   : impossible" << std::endl;

	// printing float
	if (isnanf(n) || isinff(n))
		std::cout << "float : " << static_cast<float>(n) << "f" << std::endl;
	else if (n <= std::numeric_limits<float>::max() && n >= (std::numeric_limits<float>::max() * -1 - 1))
		std::cout << "float : " << static_cast<float>(n) << "f" << std::endl;
	else
		std::cout << "float : impossible" << std::endl;

	// printing double
	std::cout << std::fixed << "double: " << n << std::endl;
}