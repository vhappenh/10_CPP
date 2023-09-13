/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:55:10 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/13 14:45:11 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int	main(int ac, char **av) {
	
	if (ac != 2) {
		std::cout << "Wrong amount of arguments!" << std::endl;
		return (1);
	}
	
	ScalarConverter	a;
	std::cout << std::endl;
	a.convert(av[1]);
	std::cout << std::endl;
	return (0);
}