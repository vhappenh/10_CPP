/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:41:35 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/20 10:40:38 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "----------first test-----------" << std::endl;
	try {
		Bureaucrat a("Bernd", 1);
	}
	catch (const std::exception& e1) {
		std::cerr << "Exception: " << e1.what() << std::endl;
	}
	std::cout << std::endl;
	
	
	std::cout << "----------second test----------" << std::endl;
	try {
		Bureaucrat b("Thomas", -5);
	}
	catch (const std::exception& e2) {
		std::cerr << "Exception: " << e2.what() << std::endl;
	}
	std::cout << std::endl;
	
	
	std::cout << "----------third test----------" << std::endl;
	Bureaucrat c("Maria", 2);
	std::cout << std::endl;
	
	std::cout << c.getName() << std::endl;
	std::cout << c.getGrade() << std::endl;
	std::cout << std::endl;
	
	try {
		c.incrementGrade();
	}
	catch (const std::exception& e3) {
		std::cerr << "Exception: " << e3.what() << std::endl;
	}
	std::cout << c.getGrade() << std::endl;
	std::cout << std::endl;
	
	try {
		c.incrementGrade();;
	}
	catch (const std::exception& e4) {
		std::cerr << "Exception: " << e4.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << c.getGrade() << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;
	return (0);
}