/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:30:04 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/13 14:55:00 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main( void ) {
	int		i_arr[10];
	double	d_arr[10];
	char	c_arr[10];
	for (int i = 0; i < 10; i++)
		i_arr[i] = i;
	for (int i = 0; i < 10; i++)
		d_arr[i] = i + 0.1;
	for (int i = 0; i < 10; i++)
		c_arr[i] = 'A' + i;

	std::cout << std::endl;
	std::cout << "-----------------int array test------------------" << std::endl;
	iter(i_arr, 10, print_element<int>);
	iter(i_arr, 10, increment_element<int>);
	std::cout << std::endl;
	iter(i_arr, 10, print_element<int>);
	std::cout << std::endl << std::endl;
	std::cout << "----------------double array test----------------" << std::endl;
	iter(d_arr, 10, print_element<double>);
	iter(d_arr, 10, increment_element<double>);
	std::cout << std::endl;
	iter(d_arr, 10, print_element<double>);
	std::cout << std::endl << std::endl;
	std::cout << "-----------------char array test-----------------" << std::endl;
	iter(c_arr, 10, print_element<char>);
	iter(c_arr, 10, increment_element<char>);
	std::cout << std::endl;
	iter(c_arr, 10, print_element<char>);
	std::cout << std::endl << std::endl;
	return (0);
}
