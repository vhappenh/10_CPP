/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:23:59 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/28 12:50:35 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {(void)other;}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return (*this); }

PmergeMe::~PmergeMe() {}

/************************************* vector part *************************************/

static unsigned long	jakobsthal(long n) {
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return jakobsthal(n - 1) + 2 * jakobsthal(n - 2);
}

static void	binary_insertion(svec& pend, spair nbr, int high) {
	int 	low = 0;
	int		mid = high / 2;

	while (low != high) {
		if (nbr.first > pend.at(mid).first) {
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
	pend.insert(pend.begin() + mid, nbr);
}

static unsigned int	get_index(unsigned int nbr, svec pend) {
	unsigned int index = 0;
	
	for (svec::iterator it = pend.begin(); it != pend.end(); it++) {
		if (nbr == it->second)
			break ;
		index++;
	}
	return (index);
}

static unsigned int	first_nbr(svec&main, svec pend) {
	svec::iterator it;
	for (it = pend.begin(); it != pend.end(); it++) {
		if (it->first == main.begin()->second) {
			main.insert(main.begin(), *it);
			break ;
		}
	}
	return (it->first);
}

static void	insert(svec& main, svec pend) {
	int				count = pend.size();
	int				jakobs_mod = 2;
	int 			jakobs_range = 0;
	unsigned int	high;
	unsigned int	jakob;
	unsigned int	first;

	if (count == 0)
		return ;
	first = first_nbr(main, pend);
	count--;
	while(count) {
		if (jakobs_range <= 0) {
			jakobs_range = jakobsthal(jakobs_mod) - jakobsthal(jakobs_mod - 1);
			jakob = jakobsthal(jakobs_mod) - 1;
		}
		if (jakob >= pend.size())
			jakob = pend.size() - 1;
		if (pend.at(jakob).first == first) {
			jakobs_range--;
			if (jakobs_range <= 0)
				jakobs_mod++;
			jakob--;
			continue;
		}
		high = get_index(pend.at(jakob).first, main);
		binary_insertion(main, pend.at(jakob), high);
		jakobs_range--;
		if (jakobs_range <= 0)
			jakobs_mod++;
		count--;
		jakob--;
	}
}

static svec	ford_johnson(svec pend) {
	svec	main;
	
	if (pend.size() < 2)
		return (pend);
	for (svec::iterator it = pend.begin(); it != pend.end(); it++) {
		spair tmp;
		if ((it + 1) != pend.end() && it->first > (it + 1)->first) {
			tmp.first = it->first;
			tmp.second = (it + 1)->first;
			main.push_back(tmp);
			pend.erase(it);
		}
		else if ((it + 1) != pend.end()) {
			tmp.first = (it + 1)->first;
			tmp.second = it->first;
			main.push_back(tmp);
			pend.erase((it + 1));
		}
	}
	main = ford_johnson(main);
	insert(main, pend);
	return (main);
}

std::vector<unsigned int>	PmergeMe::vec_solve(char **input) {
	svec 						pend;				
	std::vector<unsigned int>	result;

	for (int i = 0; input[i]; i++) {
		spair temp_pair;
		temp_pair.first = atoi(input[i]);
		temp_pair.second = -1;
		pend.push_back(temp_pair);
	}
	pend = ford_johnson(pend);
	
	for (svec::iterator it = pend.begin(); it < pend.end(); it++) {
		result.push_back(it->first);
	}
	return (result);
}


/************************************* deque part *************************************/

static void	binary_insertion(sdeq& pend, spair nbr, int high) {
	int 	low = 0;
	int		mid = high / 2;

	while (low != high) {
		if (nbr.first > pend.at(mid).first) {
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
	pend.insert(pend.begin() + mid, nbr);
}

static unsigned int	get_index(unsigned int nbr, sdeq pend) {
	unsigned int index = 0;
	
	for (sdeq::iterator it = pend.begin(); it != pend.end(); it++) {
		if (nbr == it->second)
			break ;
		index++;
	}
	return (index);
}

static unsigned int	first_nbr(sdeq&main, sdeq pend) {
	sdeq::iterator it;
	for (it = pend.begin(); it != pend.end(); it++) {
		if (it->first == main.begin()->second) {
			main.insert(main.begin(), *it);
			break ;
		}
	}
	return (it->first);
}

static void	insert(sdeq& main, sdeq pend) {
	int				count = pend.size();
	int				jakobs_mod = 2;
	int 			jakobs_range = 0;
	unsigned int	high;
	unsigned int	jakob;
	unsigned int	first;

	if (count == 0)
		return ;
	first = first_nbr(main, pend);
	count--;
	while(count) {
		if (jakobs_range <= 0) {
			jakobs_range = jakobsthal(jakobs_mod) - jakobsthal(jakobs_mod - 1);
			jakob = jakobsthal(jakobs_mod) - 1;
		}
		if (jakob >= pend.size())
			jakob = pend.size() - 1;
		if (pend.at(jakob).first == first) {
			jakobs_range--;
			if (jakobs_range <= 0)
				jakobs_mod++;
			jakob--;
			continue;
		}
		high = get_index(pend.at(jakob).first, main);
		binary_insertion(main, pend.at(jakob), high);
		jakobs_range--;
		if (jakobs_range <= 0)
			jakobs_mod++;
		count--;
		jakob--;
	}
}

static sdeq	ford_johnson(sdeq pend) {
	sdeq	main;
	
	if (pend.size() < 2)
		return (pend);
	for (sdeq::iterator it = pend.begin(); it != pend.end();) {
		spair tmp;
		if ((it + 1) != pend.end() && it->first > (it + 1)->first) {
			tmp.first = it->first;
			tmp.second = (it + 1)->first;
			main.push_back(tmp);
			pend.erase(it);
			it++;
		}
		else if ((it + 1) != pend.end()) {
			tmp.first = (it + 1)->first;
			tmp.second = it->first;
			main.push_back(tmp);
			pend.erase((it + 1));
			it++;
		}
		if (it != pend.end())
			it++;
	}
	main = ford_johnson(main);
	insert(main, pend);
	return (main);
}

std::deque<unsigned int>	PmergeMe::deq_solve(char **input) {
	sdeq 						pend;				
	std::deque<unsigned int>	result;

	for (int i = 0; input[i]; i++) {
		spair temp_pair;
		temp_pair.first = atoi(input[i]);
		temp_pair.second = -1;
		pend.push_back(temp_pair);
	}
	pend = ford_johnson(pend);
	
	for (sdeq::iterator it = pend.begin(); it < pend.end(); it++) {
		result.push_back(it->first);
	}
	return (result);
}