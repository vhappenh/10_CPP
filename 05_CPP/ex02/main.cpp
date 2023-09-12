/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:41:35 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/07 15:45:57 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main()
{
// initialising one bureaucrat
	Bureaucrat c("Maria", 2);
	std::cout << c.getName() << std::endl;
	std::cout << c.getGrade() << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

// initialising one form
	AForm a("Tax refund", 75, 1);
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
		AForm		y("testform", 75, 1);
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