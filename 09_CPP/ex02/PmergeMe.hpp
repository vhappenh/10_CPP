/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:24:11 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/09 11:43:48 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <limits>

class PmergeMe {
private:
	std::vector<unsigned int>	vecty;
	std::list<unsigned int>		listy;
public:
	PmergeMe();
	PmergeMe(char **input);
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void	solve();
} ;