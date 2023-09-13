/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:49:00 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/13 17:05:48 by vhappenh         ###   ########.fr       */
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

int	get_precision(std::string input) {
	int i;
	if (input.find_first_of('.', 0) == input.npos)
		return (0);
	i = input.find_first_of('.', 0) + 1;
	int p = 0;
	for (int j = i; input[j]; j++) {
		p++;
		if (input[j] != '0')
			return (0);
	}
	if (p > 4)
		return (4);
	return (p);
}

void ScalarConverter::convert(std::string input) {
	
	double	n = strtod(input.c_str(), NULL);
	if (n == 0 && input.length() == 1 && input[0] != '0')
		n = static_cast<double>(input[0]);
	int p = get_precision(input);
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

	// printing float   ######################Error with input 42; I'm missing the .0 if there is nothing behind the . or there is none##############
	if (isnanf(n) || isinff(n))
		std::cout << "float : " << static_cast<float>(n) << "f" << std::endl;
	else if (n <= std::numeric_limits<float>::max() && n >= (std::numeric_limits<float>::max() * -1 - 1)) {
		if (input.find_first_of('.', 0) == input.npos || input.find_first_of('.', 0) + 1 == input.length())
			std::cout << "float : " << static_cast<float>(n) << ".0f" << std::endl;
		else if (p == 0) 
			std::cout << "float : " << static_cast<float>(n) << "f" << std::endl;
		else
			std::cout << "float : " << static_cast<float>(n) << "." << std::string(p, '0') << "f" << std::endl;	
	}
	else
		std::cout << "float : impossible" << std::endl;

	// printing double
	std::cout << std::fixed << "double: " << n << std::endl;
}