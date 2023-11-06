/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:51:49 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/06 13:49:54 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Wrong amount of arguments!\n";
		return (1);
	}
	try {
		std::cout << RPN::resolve(av[1]) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}
	return (0);
}