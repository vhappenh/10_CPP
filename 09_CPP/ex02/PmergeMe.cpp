/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:23:59 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/09 13:08:29 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {(void)other;}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return (*this); }

PmergeMe::~PmergeMe() {}

void	PmergeMe::solve(std::vector<unsigned int> cont) {
	(void)cont;
}

void	PmergeMe::solve(std::list<unsigned int> cont) {

	(void)cont;
}