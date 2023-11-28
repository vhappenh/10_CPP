/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:23:30 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/28 18:47:58 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool	check_input(int ac, char **av) {
	double 						d;
	std::vector<std::string>	store;
	if (ac == 1) {
		std::cout << "No input to process!\n";
		return (true);
	}
	for (int i = 1; av[i]; i++) {
		std::string lol = av[i];
		if (lol.find_first_not_of("0123456789") != std::string::npos) {
			std::cout << "Error reading input. Wrong characters detected!\n";
			return (true);
		}
		d = strtod(av[i], NULL);
		if (d < std::numeric_limits<unsigned int>::min() || d > std::numeric_limits<unsigned int>::max()) {
			std::cerr << "Input out of unsigned int range!\n";
			return (true);
		}
		store.push_back(lol);
	}
	// if (check_for_doubles) {
	// 	std::cerr << "No doubles in input allowed!\n";
	// 		return (true);
	// 	}
	// }
	return (false);
}

static void print_input(char **av) {
	std::cout << "Before: ";
	for (int i = 1; av[i]; i++) {
		std::cout << strtod(av[i], NULL) << " ";
	}
	std::cout << "\n";
}

int	main(int ac, char **av) {
	std::vector<unsigned int> 	vecty;
	std::deque<unsigned int>	dequy;
	clock_t						start[2], end[2];

	if (check_input(ac, av))
		return (1);
	print_input(av);

	/* start of vector version */
	start[0] = clock();
	vecty = PmergeMe::vec_solve(&av[1]);
	std::cout << "Result vector: ";
	for (std::vector<unsigned int>::iterator it = vecty.begin(); it != vecty.end(); it++) {
		std::cout << *it << " "; 
	}
	end[0] = clock();

	std::cout << "\n";
	
	/* start of list version */
	start[1] = clock();
	dequy = PmergeMe::deq_solve(&av[1]);
	std::cout << "Result deque:  ";
	for (std::deque<unsigned int>::iterator it = dequy.begin(); it != dequy.end(); it++) {
		std::cout << *it << " "; 
	}
	end[1] = clock();
	
	/* print time */
	std::cout << "\n";
	std::cout << "Time passed using vector: " << end[0] - start[0] << "us\n";
	std::cout << "Time passed using deque:  " << end[1] - start[1] << "us\n";

	return (0);
}

