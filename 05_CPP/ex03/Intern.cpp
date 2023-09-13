/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:49:54 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/13 11:39:58 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called!" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern copy constructor called!" << std::endl;
	*this = other;
}

Intern&	Intern::operator=(const Intern& other) {
	std::cout << "Intern copy assignment operator called!" << std::endl;
	(void) other;
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern destructor called!" << std::endl;
}

AForm* Intern::makeForm(std::string formname, std::string target) {
	std::string arr[4] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *forms[] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
	for (int i = 0; i < 3; i++)
	{
		if (formname == arr[i]) {
			std::cout << "Intern creates " << formname << std::endl;
			for (int j = i + 1; j < 3; j++)
				delete forms[j];
			return (forms[i]);
		}
		else
			delete forms[i];
	}
	std::cout << "Intern could't create form. Type not found!" << std::endl;
	return NULL;
}