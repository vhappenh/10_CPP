/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:23:59 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/18 18:27:21 by vhappenh         ###   ########.fr       */
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

// static void	insert(std::vector<unsigned int>& main, std::vector<unsigned int> pend) {
// 	main.insert(main.begin(), *pend.begin());
// 	pend.erase(pend.begin());
// 	while (pend.size()) {
// 		unsigned int e = *(pend.end() - 1);
// 		if (e < *(main.begin() + 1)) {
// 			if (e < *main.begin()) {
// 				main.insert(main.begin(), e);
// 				pend.erase(pend.end() - 1);
// 			}
// 			else {
// 				main.insert(main.begin() + 1, e);
// 				pend.erase(pend.end() - 1);	
// 			}
// 		}
// 		else {
// 			if (e < *main.end()) {
// 				main.insert(main.begin() + 1, e);
// 				pend.erase(pend.end() - 1);	
// 			}
// 			else {
// 				main.insert(main.end(), e);
// 				pend.erase(pend.end() - 1);	
// 			}
// 		}	
// 	}
// 	print_vec(main, "insert main: ");
// 	print_vec(pend, "insert pend: ");
// 	std::cout << "\n";
// }

static void	insert_oag(std::vector<unsigned int>& main, std::vector<unsigned int> pend) {
	main.insert(main.begin(), *pend.begin());
	int	jakobs_mod = 3;
	unsigned int	count = pend.size() - 1;
	while (count) {
		unsigned int jakob = jakobsthal(jakobs_mod) - 1;
		// if (jakob > count) //use count instead
		// 	jakob = count;
		
		// int blub = jakobsthal(jakobs_mod);
		int i = jakob;
		while (i >= jakobsthal(jakobs_mod - 1)) {
			unsigned int e = *(pend.begin() + i);
			int 	binaryinsertindex = jakob / 2;
			int		breaky = jakob;
 			while (breaky) {
				breaky /= 2;
				if (e > main.at(binaryinsertindex)) {
					binaryinsertindex = binaryinsertindex + breaky / 2;
				}
				else {
					if (breaky / 2 || (binaryinsertindex > 0 && e > main.at(binaryinsertindex - 1)))
						binaryinsertindex = binaryinsertindex - breaky / 2;
					else
						if (binaryinsertindex)
							binaryinsertindex = binaryinsertindex - 1;
				}
			}
			main.insert(main.begin() + binaryinsertindex, e);
			count--;
			i--;
		}
		jakobs_mod++;
	}
	print_vec(main, "insert main: ");
	print_vec(pend, "insert pend: ");
	std::cout << "\n";
}

std::vector<unsigned int>	PmergeMe::solve(std::vector<unsigned int> pend) {
	std::vector<unsigned int> main;
	
	if (pend.size() < 2){
		return (pend);
	}
	else if (pend.size() == 2) {
		if (pend.at(0) > pend.at(1)){
			unsigned int help = pend.at(0);
			pend.at(0) = pend.at(1);
			pend.at(1) = help;
		}
		return (pend);
	}
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
	print_vec(main, "solve main: ");
	print_vec(pend, "solve pend: ");
	std::cout << "\n";
	main = solve(main);
	// if (pend.size() == 3)
	// 	insert(main, pend);
	// else
		insert_oag(main, pend);
	return (main);
	//print_vec(main, "last: ");
}

// void	PmergeMe::solve(std::list<unsigned int>& pend) {binaryinsertindex = binaryinsertindex + binaryinsertindex / 2;
// 	std::cout << "List:   ";
// 	for (std::list<unsigned int>::iterator it = pend.begin(); it != pend.end(); it++) {
// 		std::cout << *it << " ";
// 	}
// 	std::cout << "\n";
// }