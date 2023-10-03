/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:49:00 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/03 12:54:41 by vhappenh         ###   ########.fr       */
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
	unsigned long i = input.find_first_of('.', 0);
	if (i == std::string::npos)
		return (0);
	int p = 0;
	for (int j = i + 1; input[j]; j++) {
		p++;
	}
	return (p);
}

bool	check_input(std::string input, double &n, double &pf, double &pd) {
	char *endptr;
	n = strtod(input.c_str(), &endptr);
	if (endptr[0] && input.length() > 1 && input != "+inff" && input != "-inff" && input != "inff") {
		std::cout << "Invalid input" << std::endl;
		return (true);
	}
	
	if (n == 0 && input.length() == 1 && input[0] != '0')
		n = static_cast<double>(input[0]);
	
	pf = 1;
	pd = get_precision(input);
	
	if (pd == 0)
		pd = 1;
	else if (pd >= 6) {
		pf = 6;
		if (pd > 15)
			pd = 15;
	}
	else
		pf = pd;
	return (false);
}

void ScalarConverter::convert(std::string input) {
	double n, pf, pd;
	
	if (check_input(input, n, pf, pd))
		return ;		

	// printing char
	std::cout << "char  : ";
		if (n <= std::numeric_limits<unsigned char>::max() && n >= std::numeric_limits<unsigned char>::min())
			(std::isprint(n)) ? (std::cout << static_cast<unsigned char>(n)) : (std::cout << "non printable"); 
		else
			std::cout << "impossible";
	std::cout << std::endl;
	
	// printing int
	std::cout << "int   : ";
		if (n <= std::numeric_limits<int>::max() && n >= std::numeric_limits<int>::min())
			std::cout << static_cast<int>(n);
		else
			std::cout << "impossible";
	std::cout << std::endl;

	// printing float
	std::cout << "float : ";
		if (isnanf(n) || isinff(n))
			std::cout << static_cast<float>(n) << "f";
		else if (n <= std::numeric_limits<float>::max() && n >= (std::numeric_limits<float>::max() * -1 - 1)) 
			std::cout << std::fixed << std::setprecision(pf) << n << "f";	
		else
			std::cout << "impossible";
	std::cout << std::endl;

	// printing double
		std::cout << std::fixed << std::setprecision(pd) << "double: " << n << std::endl;
}