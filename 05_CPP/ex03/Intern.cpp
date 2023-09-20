/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:49:54 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/20 13:53:05 by vhappenh         ###   ########.fr       */
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

AForm* Intern::newShrubbery(std::string target){
		return (new ShrubberyCreationForm(target));
}

AForm* Intern::newRobotomy(std::string target){
		return (new RobotomyRequestForm(target));
}

AForm* Intern::newPresidential(std::string target){
		return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string formname, std::string target) {
	std::string arr[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (Intern::*forms[])(std::string) = {
		&Intern::newShrubbery,
		&Intern::newRobotomy,
		&Intern::newPresidential
	};
	for (int i = 0; i < 3; i++)
	{
		if (formname == arr[i]) {
			std::cout << "Intern creates " << formname << std::endl;
			return (this->*forms[i])(target);
		}
	}
	std::cout << "Intern could't create form. Type not found!" << std::endl;
	return NULL;
}