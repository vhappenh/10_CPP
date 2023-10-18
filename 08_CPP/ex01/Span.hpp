/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:05:37 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/18 17:29:07 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
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
	void	printDeque(void);
	long	shortestSpan(void);
	long	longestSpan(void) const;
} ;