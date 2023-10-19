/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:05:37 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/19 15:06:32 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <exception>
#include <limits>

class Span {
private:
	std::deque<int>	x;
	unsigned int	n;
public:
	Span(unsigned int N = 0);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void	addNumber(int n);
	void	addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	long	shortestSpan(void);
	long	longestSpan(void) const;
	void	printDeque(void);
} ;