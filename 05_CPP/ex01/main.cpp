/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:41:35 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/07 15:43:25 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
// initialising one bureaucrat
	Bureaucrat c("Maria", 2);
	std::cout << c.getName() << std::endl;
	std::cout << c.getGrade() << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

// testing with wrong inputs
	try {
		Form	a("Tax test1", 500, 100);
	}
	catch (const std::exception& a) {
		std::cerr << "Exception: " << a.what() << std::endl;
	}
	try {
		Form	a("Tax test2", 100, 500);
	}
	catch (const std::exception& a) {
		std::cerr << "Exception: " << a.what() << std::endl;
	}
	try {
		Form	a("Tax test3", -100, 100);
	}
	catch (const std::exception& a) {
		std::cerr << "Exception: " << a.what() << std::endl;
	}
	try {
		Form	a("Tax test4", 100, -100);
	}
	catch (const std::exception& a) {
		std::cerr << "Exception: " << a.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

// initialising one form
	Form a("Tax refund", 75, 1);
	std::cout << a.getName() << std::endl;
	std::cout << a.getSign() << std::endl;
	std::cout << a.getExec() << std::endl;
	std::cout << a << std::endl;

// signing form with bureaucrat
	a.beSigned(c);
	c.signForm(a);
	std::cout << std::endl;
	std::cout << std::endl;

// signing form with wrong bureaucrat
	{
		Bureaucrat 	x("testy", 100);
		Form		y("testform", 75, 1);
		try {
			x.signForm(y);
			y.beSigned(x);
			x.signForm(y);
		}
		catch (const std::exception& y) {
			std::cerr << "Exception: " << y.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	return (0);
}