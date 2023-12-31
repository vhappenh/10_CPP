/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:55:10 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/14 14:44:36 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int	main(int ac, char **av) {
	
	if (ac != 2) {
		std::cout << "Wrong amount of arguments!" << std::endl;
		return (1);
	}
	
	std::cout << std::endl;
	ScalarConverter::convert(av[1]);
	std::cout << std::endl;
	return (0);
}