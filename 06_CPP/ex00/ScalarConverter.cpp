/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:49:00 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/05 15:39:48 by vhappenh         ###   ########.fr       */
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

static std::string getType(std::string input) {
	if (input.find_first_of('.') == std::string::npos)
		return ("INT");
	else if (input.find_first_of('.') && input.find_first_of('f'))
		return ("FLOAT");
	else if (input.find_first_of('.'))
		return ("DOUBLE");
	else if (input.length() == 1)
		return ("CHAR");
	else
		return ("INVALID");
}

void ScalarConverter::convert(std::string input) {
	ScalarConverter converter;

	converter._type = getType(input);
}