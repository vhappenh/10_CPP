/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:05:40 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/17 15:51:15 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) {
	n = N;
}

Span::Span(const Span& other) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
	if (this != &other)
	{
		n = other.n;
		x = other.x;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int nbr) {
	if (x.size() + 1 >= n)
		throw std::out_of_range("Too many nbrs");
	x.push_back(nbr);
	std::sort(x.begin(), x.end());
}

void	Span::printDeque(void) {
	for (std::deque<int>::iterator it = x.begin(); it != x.end(); it++)
		std::cout << *it << "\n";	
}