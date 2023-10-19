/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:05:40 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/19 10:23:14 by vhappenh         ###   ########.fr       */
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
	if (x.size() + 1 > n)
		throw std::out_of_range("Too many nbrs");
	std::deque<int>::iterator it = std::upper_bound(x.begin(), x.end(), nbr);
	if (it != x.end())
		x.insert(it, nbr);
	else
		x.push_back(nbr);
}

long	Span::shortestSpan(void) {
	if (x.size() <= 1)
		throw std::out_of_range("Not enough elements for span");
		
	long span = std::numeric_limits<long>::max();
	long tmp;
	for (std::deque<int>::iterator it = x.begin() + 1; it != x.end(); it++) {
		tmp = *it - *(it - 1);
		if (tmp < span)
			span = tmp;
	}
	return (span);
}
long	Span::longestSpan(void) const {
	if (x.size() <= 1)
		throw std::out_of_range("Not enough elements for span");
	return (*max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end()));
}

void	Span::printDeque(void) {
	for (std::deque<int>::iterator it = x.begin(); it != x.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
}