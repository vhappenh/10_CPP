/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:41:35 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/06 16:12:26 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try {
		Bureaucrat a("Bernd", 1);
	}
	catch (const std::exception& a) {
		std::cerr << "Exception: " << a.what() << std::endl;
	}
	std::cout << std::endl;
	
	try {
		Bureaucrat b("Thomas", -5);
	}
	catch (const std::exception& b) {
		std::cerr << "Exception: " << b.what() << std::endl;
	}
	std::cout << std::endl;
	
	Bureaucrat c("Maria", 2);
	std::cout << c.getName() << std::endl;
	std::cout << c.getGrade() << std::endl;
	try {
		c.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& c) {
		std::cerr << "Exception: " << c.what() << std::endl;
	}
	std::cout << c.getGrade() << std::endl;
	try {
		c.incrementGrade();;
	}
	catch (const Bureaucrat::GradeTooHighException& c) {
		std::cerr << "Exception: " << c.what() << std::endl;
	}
	std::cout << c.getGrade() << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;
	return (0);
}