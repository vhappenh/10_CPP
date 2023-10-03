/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:48:35 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/03 14:26:31 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _name("yo") {
	std::cout << "Data default constructor called" << std::endl;
}

Data::Data(const Data& other) : _name(other._name) {
	std::cout << "Data copy constructor called" << std::endl;
	*this = other;
}

Data& Data::operator=(const Data& other) {
	std::cout << "Data assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

Data::~Data() {
	std::cout << "Data destructor called" << std::endl;
}

std::string Data::getName() {return (_name);}