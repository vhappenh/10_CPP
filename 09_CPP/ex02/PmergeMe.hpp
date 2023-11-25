/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:24:11 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/25 15:23:31 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
#include <cstdlib>
#include <limits>
#include <ctime>

typedef std::pair<unsigned int, long> spair;
typedef std::vector<std::vector<spair >	> svec;

class PmergeMe {
private:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
public:
	static std::vector<unsigned int> vec_solve(char **input);
	static std::deque<unsigned int> deq_solve(char **input);
} ;