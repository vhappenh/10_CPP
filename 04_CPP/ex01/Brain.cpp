/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:37:17 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/30 12:05:38 by vhappenh         ###   ########.fr       */
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
	for (int i = 0; i < 100; i++)
		this->setType(other.getType(i), i);
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &other)
		for (int i = 0; i < 100; i++)
			this->setType(other.getType(i), i);
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getType(int i) const
{
	return (this->ideas[i]);
}

void	Brain::setType(const std::string idea, int i)
{
	this->ideas[i] = idea;
}