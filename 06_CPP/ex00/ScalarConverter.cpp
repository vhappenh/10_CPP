/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:49:00 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/11 15:00:29 by vhappenh         ###   ########.fr       */
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

static int	get_precision(std::string input) {
	unsigned long i = input.find_first_of('.', 0);
	if (i == std::string::npos)
		return (1);
	int p = 0;
	for (int j = i + 1; input[j] && isdigit(input[j]); j++) {
		p++;
	}
	if (p == 0)
		p = 1;
	return (p);
}

static void	printChar(char c) {	isprint(c) ? std::cout << "Char:   '" << c << "'" << std::endl : std::cout << "Char:   not printable" << std::endl;}

static void	printInt(int i) {std::cout << "Int:    " << i << std::endl;}

static void	printFloat(float f, int p) {std::cout << std::fixed << std::setprecision(p) << "Float:  " << f << "f" << std::endl;}

static void	printDouble(double d, int p) {std::cout << std::fixed << std::setprecision(p) << "Double: " << d << std::endl;}

static void	isChar(std::string input) {
	std::stringstream 	ss(input);
	char				c;
	ss >> c;
	
	printChar(c);
	printInt((int)c);
	printFloat((float)c, 1);
	printDouble((double)c, 1);
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

	printFloat((float)i, 1);
	printDouble((double)i, 1);
}

static void	isFloat(std::string input) {
	float	f = strtof(input.c_str(), NULL);
	int		p = get_precision(input);
	if (p > 6)
		p = 6;

	if (f <= std::numeric_limits<unsigned char>::max() && f >= std::numeric_limits<unsigned char>::min())
		printChar(static_cast<char>(f));
	else
		std::cout << "Char:   impossible" << std::endl;

	if (f <= std::numeric_limits<int>::max() && f >= std::numeric_limits<int>::min())
		printInt(static_cast<int>(f));
	else
		std::cout << "Int:    impossible" << std::endl;
	
	printFloat(f, p);

	printDouble((double)f, p);	
}

static void	isDouble(std::string input) {
	double	d = strtod(input.c_str(), NULL);
	int		pd = get_precision(input), pf = pd;
	if (pd > 6)
		pf = 6;
	if (pd > 15)
		pd = 15;
	
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
	else if (d <= std::numeric_limits<float>::max() && d >= (std::numeric_limits<float>::max() * -1 - 1))
		printFloat(static_cast<float>(d), pf);
	else
		std::cout << "Float:  impossible" << std::endl;
		
	printDouble(d, pd);		
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
