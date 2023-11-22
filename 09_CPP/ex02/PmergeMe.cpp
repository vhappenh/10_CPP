/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:23:59 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/22 18:09:27 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {(void)other;}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return (*this); }

PmergeMe::~PmergeMe() {}

static void print_vec(std::vector<unsigned int>& vec, std::string name) {
	std::cout << name;
	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

static long	jakobsthal(long n) {
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return jakobsthal(n - 1) + 2 * jakobsthal(n - 2);
}

static unsigned int get_index( int breaky, int binaryinsertindex, unsigned int e, std::vector<unsigned int> main) {
	if (e > main.at(binaryinsertindex)) {
		if (breaky / 2)
			binaryinsertindex = binaryinsertindex + breaky / 2;
		else
			binaryinsertindex = binaryinsertindex + 1;
	}
	else {
		if (breaky / 2 || (binaryinsertindex > 0 && e > main.at(binaryinsertindex - 1)))
			binaryinsertindex = binaryinsertindex - breaky / 2;
		else
			if (binaryinsertindex)
				binaryinsertindex = binaryinsertindex - 1;
	}
	return (binaryinsertindex);
}

static void	insert(std::vector<unsigned int>& main, std::vector<unsigned int> pend) {
	int				jakobs_mod = 3;
	unsigned int	count = pend.size() - 1;

	main.insert(main.begin(), *pend.begin());
	while (count) {
		unsigned int jakob = jakobsthal(jakobs_mod) - 1;
		int i = jakob;
		
		if ((unsigned long)i >= pend.size())
			i = pend.size() - 1;

		while (i >= jakobsthal(jakobs_mod - 1)) {
			unsigned int e = *(pend.begin() + i);
			int		breaky = jakob;
			int 	binaryinsertindex = breaky / 2;
			
 			while (breaky && (unsigned long)binaryinsertindex < main.size()) {
				breaky /= 2;
				binaryinsertindex = get_index(breaky, binaryinsertindex, e, main);
			}
			main.insert(main.begin() + binaryinsertindex, e);
			count--;
			i--;
		}
		jakobs_mod++;
	}
	print_vec(main, "insert main: ");
	std::cout << "\n";
}

std::vector<unsigned int>	PmergeMe::solve(std::vector<unsigned int> pend) {
	std::vector<unsigned int> 	main;				
	
	if (pend.size() < 2)
		return (pend);
	for (std::vector<unsigned int>::iterator it = pend.begin(); it != pend.end(); it++) {
		if ((it + 1) != pend.end() && *it > *(it + 1)) {
			main.push_back(*it);
			pend.erase(it);
		}
		else if ((it + 1) != pend.end()) {
			main.push_back(*(it + 1));
			pend.erase((it + 1));
		}
	}
	main = solve(main);
	insert(main, pend);
	return (main);
}

// void	PmergeMe::solve(std::list<unsigned int>& pend) {binaryinsertindex = binaryinsertindex + binaryinsertindex / 2;
// 	std::cout << "List:   ";
// 	for (std::list<unsigned int>::iterator it = pend.begin(); it != pend.end(); it++) {
// 		std::cout << *it << " ";
// 	}
// 	std::cout << "\n";
// }