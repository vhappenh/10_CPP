/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:30:41 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/12 14:32:55 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	AForm::AForm("SchrubberyCreationForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm::AForm("SchrubberyCreationForm", 25, 5), _target(other._target) {
	std::cout << "PresidentialPardonForm copy constructor called!" << std::endl;
	*this = other;
	return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &other) {
        _target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called!" << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const {
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	(void) executor;
	return ;
}