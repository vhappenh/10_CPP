/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:48:54 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/06 12:04:35 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();
public:
	static void convert(std::string input);
} ;