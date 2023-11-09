/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:23:59 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/09 11:47:51 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **input) {
	double 		d;
	time_t		start, end;

	time(&start);
	for (int i = 0; input[i]; i++) {
		d = strtod(input[i], NULL);
		if (static_cast<unsigned int>(d) >= std::numeric_limits<unsigned int>::min()
			&& static_cast<unsigned int>(d) <= std::numeric_limits<unsigned int>::max())
		vecty.push_back(static_cast<unsigned int>(d));
		listy.push_back(static_cast<unsigned int>(d));
	}
	time(&end);
	std::cout  << "Time passed: " << start - end << "\n";
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	vecty = other.vecty;
	listy = other.listy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		(void)other;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {
	
}

void	PmergeMe::solve() {
	
}