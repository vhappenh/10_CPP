/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:23:59 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/23 16:05:28 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {(void)other;}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return (*this); }

PmergeMe::~PmergeMe() {}

// static void print_vec(std::vector<unsigned int>& vec, std::string name) {
// 	std::cout << name;
// 	for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++) {
// 		std::cout << *it << " ";
// 	}
// 	std::cout << "\n";
// }

// static void	insert(std::vector<unsigned int>& main, std::vector<unsigned int> pend) {
// 	int				jakobs_mod = 3;
// 	unsigned int	count = pend.size() - 1;

// 	main.insert(main.begin(), *pend.begin());
// 	while (count) {
// 		unsigned int jakob = jakobsthal(jakobs_mod) - 1;
// 		int i = jakob;
		
// 		if ((unsigned long)i >= pend.size())
// 			i = pend.size() - 1;

// 		while (i >= jakobsthal(jakobs_mod - 1)) {
// 			unsigned int e = *(pend.begin() + i);
// 			int		breaky = jakob;
// 			int 	binaryinsertindex = breaky / 2;
			
//  			while (breaky && (unsigned long)binaryinsertindex < main.size()) {
// 				breaky /= 2;
// 				binaryinsertindex = get_index(breaky, binaryinsertindex, e, main);
// 			}
// 			main.insert(main.begin() + binaryinsertindex, e);
// 			count--;
// 			i--;
// 		}
// 		jakobs_mod++;
// 	}
// 	print_vec(main, "insert main: ");
// 	std::cout << "\n";
// }

static unsigned long	jakobsthal(long n) {
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return jakobsthal(n - 1) + 2 * jakobsthal(n - 2);
}

static void switch_swap(std::vector<std::vector<unsigned int> >& pend, int src_index, int dst_index) {
	int				swap_index = pend.size() - 3;

	while (swap_index >= 0) {
		unsigned int temp;
		temp = pend[swap_index].at(src_index);
		pend[swap_index].erase(pend[swap_index].begin() + src_index);
		pend[swap_index].insert(pend[swap_index].begin() + dst_index, temp);
		swap_index--;
	}
}

static void	binary_insertion(std::vector<std::vector<unsigned int> >& pend, int nbr_index, int high) {
	int				insert_index = pend.size() - 1;
	unsigned int 	nbr = pend[insert_index - 1].at(nbr_index);
	int 			low = 0;
	int				mid = high / 2;

	while (low != high) {
		if (nbr > pend[insert_index].at(mid)) {
			if (low == mid)
				low++;
			else
				low = mid;
		}
		else {
			if (high == mid)
				high--;
			else
				high = mid;
		}
		mid = (high - low) / 2 + low;
	}
	pend[insert_index].insert(pend[insert_index].begin() + mid, nbr);
	switch_swap(pend, nbr_index, mid);
}

static void first_nbr(std::vector<std::vector<unsigned int> >& pend, bool issorted) {
	
	unsigned int	max_index = pend.size() - 1;
	int				swap_index;

	pend[max_index].insert(pend[max_index].begin(), *pend[max_index - 1].begin());
	pend[max_index - 1].erase(pend[max_index - 1].begin());
	swap_index = max_index - 2;
	if (!issorted) {
		while (swap_index >= 0) {
			unsigned int temp;
			temp = *pend[swap_index].begin();
			*pend[swap_index].begin() = *(pend[swap_index].begin() + 1);
			*(pend[swap_index].begin() + 1) = temp;
			swap_index--;
		}	
	}
}

static void	insert(std::vector<std::vector<unsigned int> >& pend, long misfit, bool issorted) {
	unsigned int	max_index = pend.size() - 1;
	int				jakobs_mod = 3;
	while (jakobsthal(jakobs_mod) < pend[max_index - 1].size())
		jakobs_mod++;
	unsigned int	high;
	int				eraserhead = 0;
	
	if (max_index == 0)
		return ;
	first_nbr(pend, issorted);
	eraserhead++;
	while (pend[max_index - 1].size()) {
		unsigned int jakob = jakobsthal(jakobs_mod) - 1 - eraserhead;
		if (jakob >= pend[max_index - 1].size())
			jakob = pend[max_index - 1].size() - 1;
		if (pend[max_index - 1].size() == 1)
			eraserhead++;
		
		if (pend[max_index - 1].at(jakob) == misfit)
			high = pend[max_index].size();
		else
			high = jakob + eraserhead;
		if (high > pend[max_index].size())
			high = pend[max_index].size();
		binary_insertion(pend, jakob, high);
		pend[max_index - 1].erase(pend[max_index - 1].begin() + jakob);
		eraserhead++;
	}
	pend.erase(pend.begin() + max_index - 1);
}

static std::vector<std::vector<unsigned int> >	ford_johnson(std::vector<std::vector<unsigned int> > pend) {
	std::vector<unsigned int> 	main;
	long 						misfit = -1;
	int							i = pend.size() -1;	
	bool						first = true;
	bool						issortedquestionmark = false;
	
	if (pend[i].size() < 2)
		return (pend);
	if (pend[i].size() % 2)
		misfit = *(pend[i].end() - 1);
	for (std::vector<unsigned int>::iterator it = pend[i].begin(); it != pend[i].end(); it++) {
		if ((it + 1) != pend[i].end() && *it > *(it + 1)) {
			main.push_back(*it);
			pend[i].erase(it);
			first = false;
		}
		else if ((it + 1) != pend[i].end()) {
			main.push_back(*(it + 1));
			pend[i].erase((it + 1));
			if (first) {
				issortedquestionmark = true;
				first = false;
			}
		}
	}
	pend.push_back(main);
	pend = ford_johnson(pend);
	insert(pend, misfit, issortedquestionmark);
	return (pend);
}

std::vector<unsigned int>	PmergeMe::solve(char **input) {
	std::vector<std::vector<unsigned int> >	pend;
	std::vector<unsigned int> 				temp;			
	
	for (int i = 0; input[i]; i++)
		temp.push_back(atoi(input[i]));
	pend.push_back(temp);
	pend = ford_johnson(pend);
	return (pend[0]);
}

// void	PmergeMe::solve(std::list<unsigned int>& pend) {binaryinsertindex = binaryinsertindex + binaryinsertindex / 2;
// 	std::cout << "List:   ";
// 	for (std::list<unsigned int>::iterator it = pend.begin(); it != pend.end(); it++) {
// 		std::cout << *it << " ";
// 	}
// 	std::cout << "\n";
// }