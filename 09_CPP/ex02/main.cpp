/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:23:30 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/09 11:40:55 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "No input to process!\n";
	}
	for (int i = 1; av[i]; i++) {
		std::string lol = av[i];
		if (lol.find_first_not_of("0123456789") != std::string::npos) {
			std::cout << "Error reading input. Wrong characters detected!\n";
			return (1);
		}
	}
	PmergeMe lolly(&av[1]);
	return (0);
}