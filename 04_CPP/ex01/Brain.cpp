/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:37:17 by vhappenh          #+#    #+#             */
/*   Updated: 2023/08/29 15:23:49 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &other)
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}