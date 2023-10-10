/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:49:00 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/10 15:10:34 by vhappenh         ###   ########.fr       */
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

static void	printChar(char c) {
	if (isprint(c))
		std::cout << "Char:   " << c << std::endl;
	else
		std::cout << "Char:   not printable" << std::endl;
}

static void	printInt(int i) {
	std::cout << "Int:    " << i << std::endl;
}

static void	printFloat(float f, bool lvl, bool dot) {
	if (isnanf(f) || isinff(f)) {
		std::cout << "Float:  " << f << "f" << std::endl;
		return ;
	}
	if (lvl)
		std::cout << "Float:  " << f << ".0f" << std::endl;
	else if (dot)
		std::cout << "Float:  " << f << ".0f" << std::endl;
	else
		std::cout << "Float:  " << f << "f" << std::endl;
}

static void	printDouble(double d, bool lvl, bool dot) {
	if (lvl)
		std::cout << "Double: " << d << ".0" << std::endl;
	else if (dot)
		std::cout << "Double: " << d << ".0" << std::endl;
	else
		std::cout << "Double: " << d << std::endl;
}

static void	isChar(std::string input) {
	std::stringstream 	ss(input);
	char				c;
	ss >> c;
	
	printChar(c);
	printInt((int)c);
	printFloat((float)c, true, false);
	printDouble((double)c, true, false);
}

static void	isInt(std::string input) {
	std::stringstream 	ss(input);
	int					i;
	ss >> i;
	
	if (i <= std::numeric_limits<unsigned char>::max() && i >= std::numeric_limits<unsigned char>::min())
		printChar(static_cast<char>(i));
	else
		std::cout << "Char:   impossible" << std::endl;

	if (i <= std::numeric_limits<int>::max() && i >= std::numeric_limits<int>::min())
		printInt(i);
	else
		std::cout << "Int:    impossible" << std::endl;
	printFloat((float)i, true, false);
	printDouble((double)i, true, false);
	
}

static void	isFloat(std::string input) {
	float	f = strtof(input.c_str(), NULL);
	int		i = input.find_first_of('.');

	if (f <= std::numeric_limits<unsigned char>::max() && f >= std::numeric_limits<unsigned char>::min())
		printChar(static_cast<char>(f));
	else
		std::cout << "Char:   impossible" << std::endl;

	if (f <= std::numeric_limits<int>::max() && f >= std::numeric_limits<int>::min())
		printInt(static_cast<int>(f));
	else
		std::cout << "Int:    impossible" << std::endl;
	
	if (i && input[i + 1] == '\0')
		printFloat(f, false, true);
	else
		printFloat(f, false, false);
	printDouble((double)f, false, false);	
}

static void	isDouble(std::string input) {
	double				d = strtod(input.c_str(), NULL);
	int		i = input.find_first_of('.');
	
	if (d <= std::numeric_limits<unsigned char>::max() && d >= std::numeric_limits<unsigned char>::min())
		printChar(static_cast<char>(d));
	else
		std::cout << "Char:   impossible" << std::endl;

	if (d <= std::numeric_limits<int>::max() && d >= std::numeric_limits<int>::min())
		printInt(static_cast<int>(d));
	else
		std::cout << "Int:    impossible" << std::endl;
		
	if (isnanf(static_cast<float>(d)) || isinff(static_cast<float>(d)))
		std::cout << "Float:  " << static_cast<float>(d) << "f" << std::endl;
	else if (d <= std::numeric_limits<float>::max() && d >= (std::numeric_limits<float>::max() * -1 - 1)) {
		if (i && input[i + 1] == '\0')
			printFloat(static_cast<float>(d), false, true);
		else
			printFloat(static_cast<float>(d), false, false);
	}
	else
		std::cout << "Float:  impossible" << std::endl;
	if (i && input[i + 1] == '\0')
		printDouble(d, false, true);
	else
		printDouble(d, false, false);		
}

static std::string	check_input(std::string input) {
	char *endptr;
	double n = strtod(input.c_str(), &endptr);

	if (endptr[0] && (endptr[0] != 'f' || endptr[1] != '\0') && input.length() > 1 && input != "+inff" && input != "-inff" && input != "inff" && input != "nanf")
		return ("INVALID");
	if (n <= std::numeric_limits<unsigned char>::max() && n >= std::numeric_limits<unsigned char>::min()
		&& n == 0 && input.length() == 1 && input[0] != '0')
		return ("CHAR");
	if (n <= std::numeric_limits<int>::max() && n >= std::numeric_limits<int>::min() && input.find_first_of(".") == std::string::npos && endptr[0] != 'f')
		return ("INT");
	if (((n <= std::numeric_limits<float>::max() && n >= (std::numeric_limits<float>::max() * -1 - 1)) && endptr[0] == 'f') 
		|| ((isnanf(static_cast<float>(n)) || isinff(static_cast<float>(n))) && endptr[0] == 'f'))
		return ("FLOAT");
	else
		return ("DOUBLE");
}

void ScalarConverter::convert(std::string input) {
	std::string type = check_input(input);

	if (type == "CHAR")
		isChar(input);
	else if (type == "INT")
		isInt(input);
	else if (type == "FLOAT")
		isFloat(input);
	else if (type == "DOUBLE")
		isDouble(input);
	else
		std::cout << "Invalid input" << std::endl;
}
