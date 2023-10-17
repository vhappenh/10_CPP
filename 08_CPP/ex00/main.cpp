/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:40:03 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/17 15:04:51 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void) {
	std::deque<int> test1;
	for (int i = 0; i < 10; i++)
		test1.push_back(i);
	try {
		std::deque<int>::iterator it = ::easyfind<std::deque<int> >(test1, 3);
		std::cout << *it << std::endl;
	}	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		std::deque<int>::iterator it = ::easyfind<std::deque<int> >(test1, 13);
		std::cout << *it << std::endl;
	}	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}