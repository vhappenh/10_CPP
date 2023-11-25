/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:23:59 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/25 15:23:19 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {(void)other;}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return (*this); }

PmergeMe::~PmergeMe() {}

// static void switch_swap(std::vector<std::vector<unsigned int> >& pend, int src_index, int dst_index) {
// 	int				swap_index = pend.size() - 3;

// 	while (swap_index >= 0) {
// 		unsigned int temp;
// 		temp = pend[swap_index].at(src_index);
// 		pend[swap_index].erase(pend[swap_index].begin() + src_index);
// 		pend[swap_index].insert(pend[swap_index].begin() + dst_index, temp);
// 		swap_index--;
// 	}
// }

/************************************* vector part *************************************/

static unsigned long	jakobsthal(long n) {
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return jakobsthal(n - 1) + 2 * jakobsthal(n - 2);
}

static void	binary_insertion(svec& pend, int nbr_index, int high) {
	int		insert_index = pend.size() - 1;
	spair	nbr = pend[insert_index - 1].at(nbr_index);
	int 	low = 0;
	int		mid = high / 2;

	while (low != high) {
		if (nbr.first > pend[insert_index].at(mid).first) {
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
	//switch_swap(pend, nbr_index, mid);
}

static void first_nbr(svec& pend, bool issorted) {
	
	unsigned int	max_index = pend.size() - 1;
	int				swap_index;
	(void)issorted;

	pend[max_index].insert(pend[max_index].begin(), *pend[max_index - 1].begin());
	pend[max_index - 1].erase(pend[max_index - 1].begin());
	swap_index = max_index - 2;
	if (!issorted && swap_index >= 0) {
			spair temp;
			temp = *pend[swap_index].begin();
			*pend[swap_index].begin() = *(pend[swap_index].begin() + 1);
			*(pend[swap_index].begin() + 1) = temp;
			swap_index--;
	}
}

static unsigned int	get_index(unsigned int nbr, std::vector<spair > pend) {
	unsigned int i = 0;
	
	for (std::vector<spair >::iterator it = pend.begin(); it != pend.end(); it++) {
		if (nbr == it->second)
			break ;
		i++;
	}
	return (i);
}

static void	insert(svec& pend, long misfit, bool issorted) {
	unsigned int	max_index = pend.size() - 1;
	int				jakobs_mod = 3;
	int 			jakobs_range = 0;
	unsigned int	high;
	int				eraserhead = 0;
	
	(void)misfit;
	if (max_index == 0)
		return ;
	first_nbr(pend, issorted);
	eraserhead++;
	while (pend[max_index - 1].size()) {
		if (!jakobs_range)
			jakobs_range = jakobsthal(jakobs_mod) - jakobsthal(jakobs_mod - 1);
			
		unsigned int jakob = jakobsthal(jakobs_mod) - 1 - eraserhead;
		if (jakob >= pend[max_index - 1].size())
			jakob = pend[max_index - 1].size() - 1;
			
		if (pend[max_index - 1].size() == 1) // wtf is this doing?
			eraserhead++;
		
		if (pend[max_index - 1].at(jakob).first == misfit)
			high = pend[max_index].size();
		else {
			high = get_index(pend[max_index - 1].at(jakob).first, pend[max_index]);
			if (high > pend[max_index].size())
				high = pend[max_index].size();
		}
		
		binary_insertion(pend, jakob, high);
		pend[max_index - 1].erase(pend[max_index - 1].begin() + jakob);
		eraserhead++;
		jakobs_range--;
		if (!jakobs_range)
			jakobs_mod++;
	}
	pend.erase(pend.begin() + max_index - 1);
}

static svec	ford_johnson(svec pend) {
	std::vector<spair >	main;
	long 						misfit = -1;
	int							i = pend.size() -1;	
	bool						first = true;
	bool						issortedquestionmark = false;
	
	if (pend[i].size() < 2)
		return (pend);
	if (pend[i].size() % 2)
		misfit = (pend[i].end() - 1)->first;
	for (std::vector<spair >::iterator it = pend[i].begin(); it != pend[i].end(); it++) {
		spair tmp;
		if ((it + 1) != pend[i].end() && it->first > (it + 1)->first) {
			tmp.first = it->first;
			tmp.second = (it + 1)->first;
			main.push_back(tmp);
			pend[i].erase(it);
			first = false;
		}
		else if ((it + 1) != pend[i].end()) {
			tmp.first = (it + 1)->first;
			tmp.second = it->first;
			main.push_back(tmp);
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

std::vector<unsigned int>	PmergeMe::vec_solve(char **input) {
	svec 													pend;		
	std::vector<std::pair<unsigned int, long > >	temp;			
	std::vector<unsigned int>								result;

	for (int i = 0; input[i]; i++) {
		std::pair<unsigned int, long > temp_pair;
		temp_pair.first = atoi(input[i]);
		temp.push_back(temp_pair);
	}
	pend.push_back(temp);
	pend = ford_johnson(pend);
	
	for (std::vector<std::pair<unsigned int, long > >::iterator it = pend[0].begin(); it < pend[0].end(); it++) {
		result.push_back(it->first);
	}
	return (result);
}


/************************************* deque part *************************************/
static void	binary_insertion(std::deque<std::deque<unsigned int> >& pend, int nbr_index, int high) {
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
}

static void first_nbr(std::deque<std::deque<unsigned int> >& pend, bool issorted) {
	
	unsigned int	max_index = pend.size() - 1;
	int				swap_index;
	(void)issorted;

	pend[max_index].insert(pend[max_index].begin(), *pend[max_index - 1].begin());
	pend[max_index - 1].erase(pend[max_index - 1].begin());
	swap_index = max_index - 2;
	if (!issorted && swap_index >= 0) {
			unsigned int temp;
			temp = *pend[swap_index].begin();
			*pend[swap_index].begin() = *(pend[swap_index].begin() + 1);
			*(pend[swap_index].begin() + 1) = temp;
			swap_index--;
	}
}

static void	insert(std::deque<std::deque<unsigned int> >& pend, long misfit, bool issorted) {
	unsigned int	max_index = pend.size() - 1;
	int				jakobs_mod = 3;
	int 			jakobs_range = 0;
	unsigned int	high;
	int				eraserhead = 0;
	
	if (max_index == 0)
		return ;
	first_nbr(pend, issorted);
	eraserhead++;
	while (pend[max_index - 1].size()) {
		if (!jakobs_range)
			jakobs_range = jakobsthal(jakobs_mod) - jakobsthal(jakobs_mod - 1);
		unsigned int jakob = jakobsthal(jakobs_mod) - 1 - eraserhead;
		if (jakob >= pend[max_index - 1].size())
			jakob = pend[max_index - 1].size() - 1;
		if (pend[max_index - 1].size() == 1)
			eraserhead++;
		
		if (pend[max_index - 1].at(jakob) == misfit)
			high = pend[max_index].size();
		else
			high = jakob + 2 * eraserhead;
		if (high > pend[max_index].size())
			high = pend[max_index].size();
		binary_insertion(pend, jakob, high);
		pend[max_index - 1].erase(pend[max_index - 1].begin() + jakob);
		eraserhead++;
		jakobs_range--;
		if (!jakobs_range)
			jakobs_mod++;
	}
	pend.erase(pend.begin() + max_index - 1);
}

static std::deque<std::deque<unsigned int> >	ford_johnson(std::deque<std::deque<unsigned int> > pend) {
	std::deque<unsigned int> 	main;
	long 						misfit = -1;
	int							i = pend.size() -1;	
	bool						first = true;
	bool						issortedquestionmark = false;
	
	if (pend[i].size() < 2)
		return (pend);
	if (pend[i].size() % 2)
		misfit = *(pend[i].end() - 1);
	for (std::deque<unsigned int>::iterator it = pend[i].begin(); it != pend[i].end();) {
		if ((it + 1) != pend[i].end() && *it > *(it + 1)) {
			main.push_back(*it);
			pend[i].erase(it);
			first = false;
			it++;
		}
		else if ((it + 1) != pend[i].end()) {
			main.push_back(*(it + 1));
			pend[i].erase((it + 1));
			if (first) {
				issortedquestionmark = true;
				first = false;
			}
			it++;
		}
		if (it != pend[i].end())
			it++;
	}
	pend.push_back(main);
	pend = ford_johnson(pend);
	insert(pend, misfit, issortedquestionmark);
	return (pend);
}

std::deque<unsigned int>	PmergeMe::deq_solve(char **input) {
	std::deque<std::deque<unsigned int> >	pend;
	std::deque<unsigned int> 				temp;			
	
	for (int i = 0; input[i]; i++)
		temp.push_back(atoi(input[i]));
	pend.push_back(temp);
	pend = ford_johnson(pend);
	return (pend[0]);
}