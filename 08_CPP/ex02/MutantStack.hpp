/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:28:21 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/23 13:25:03 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	
	MutantStack() {};
	MutantStack(const MutantStack& other) {
		*this = other;
	}
	MutantStack& operator=(const MutantStack& other) {
		std::stack<T, std::deque<T> >::operator=(other);
		return (*this);
	}
	~MutantStack() {};

	iterator begin() { return (this->c.begin()); };
	iterator end() { return (this->c.end()); };
} ;