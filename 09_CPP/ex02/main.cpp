/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:23:30 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/09 13:07:45 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	std::vector<unsigned int> 	vecty;
	std::list<unsigned int>		listy;
	double 						d;
	time_t						start[2], end[2];

	/* input check and printing it out */
	if (ac == 1) {
		std::cout << "No input to process!\n";
	}
	std::cout << "Before: ";
	for (int i = 1; av[i]; i++) {
		std::string lol = av[i];
		if (lol.find_first_not_of("0123456789") != std::string::npos) {
			std::cout << "Error reading input. Wrong characters detected!\n";
			return (1);
		}
		d = strtod(av[i], NULL);
		if (d <= std::numeric_limits<unsigned int>::min() || d >= std::numeric_limits<unsigned int>::max()) {
			std::cerr << "Input out of unsigned int range!\n";
			return (2);
		}
		else
			std::cout << d << " ";
	}
	std::cout << "\n";

	/* start of vector version */
	time(&start[0]);
	for (int i = 1; av[i]; i++)
		vecty.push_back(atoi(av[i]));
	PmergeMe::solve(vecty);
	time(&end[0]);


	/* start of list version */
	time(&start[1]);
	for (int i = 1; av[i]; i++)
		listy.push_back(atoi(av[i]));
	PmergeMe::solve(listy);
	time(&end[1]);
	
	//print time
	std::cout  << "Time passed using vect: " << start[0] - end[0] << "\n";
	std::cout  << "Time passed using list: " << start[1] - end[1] << "\n";

	return (0);
}