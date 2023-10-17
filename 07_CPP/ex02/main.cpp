/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:30:04 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/17 10:54:18 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"
#include "Array.hpp"

int main( void ) {
	// first test with index out of bound
	std::cout << "-------test1-------" << std::endl;
	Array<int> test1;
	std::cout << "size: " << test1.size() << std::endl;
	try {
		test1[1] = 2;
	} 
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	
	// second test with big enough index, changing value in array
	std::cout << "-------test2-------" << std::endl;
	Array<int> test2(5);
	std::cout << "size: " << test2.size() << std::endl;
	try {
		test2[0] = 2;
		std::cout << test2[0] << std::endl;
	} 
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	
	// third test, changing three values, iterating through and printing
	std::cout << "-------test3-------" << std::endl;
	Array<char> test3(10);
	std::cout << "size: " << test3.size() << std::endl;
	try {
		test3[0] = 'a';
		test3[1] = 'b';
		test3[2] = 'c';
		for (int i = 0; i < 3; i++)
			std::cout << test3[i];
		std::cout << std::endl;
	} 
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	return (0);
}
