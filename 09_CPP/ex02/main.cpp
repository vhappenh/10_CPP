/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:23:30 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/07 14:22:04 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	std::vector<int> vec;
	std::deque<int> que;
	(void)av;
	
	if (ac == 1) {
		std::cout << "No input to process!\n";
	}
	for (int i = 0; av[1][i]; i++) {
		if (!isdigit(av[1][0]) && av[i][i] != ' ') {
			std::cout << "Error reading input. Wrong characters detected!\n";
			return (1);
		}
		vec.push_back(atoi(&av[1][i]));
		que.push_back(atoi(&av[1][i]));
		for (int j = 0; av[1][i + j] != ' '; j++)
			;
	}
	return (0);
}