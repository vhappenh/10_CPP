/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:33:31 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/15 09:51:26 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Serialzier default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& other) {
	std::cout << "Serialzier copy constructor called" << std::endl;
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other) {
	std::cout << "Serialzier assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

Serializer::~Serializer() {
	std::cout << "Serialzier destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}