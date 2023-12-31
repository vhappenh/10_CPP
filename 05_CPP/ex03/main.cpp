/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:41:35 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/20 11:12:59 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main() {
	Intern someRandomIntern;
	AForm* rrf;
	std::cout << std::endl;

	std::cout << "--------------starting test--------------" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << "---------------test ended----------------" << std::endl;
	std::cout << std::endl;
	delete rrf;
	std::cout << std::endl;
	return (0);
}