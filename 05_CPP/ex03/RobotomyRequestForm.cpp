/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:31:56 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/13 10:37:14 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm::AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm::AForm("RobotomyRequestForm", 72, 45), _target(other._target) {
	std::cout << "RobotomyRequestForm copy constructor called!" << std::endl;
	*this = other;
	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &other) {
        _target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called!" << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const {
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (getExec() >= executor.getGrade()) {
		std::cout << _target << " has been robotomized successfully 50% of the time." << std::endl;
	}
	else
		throw GradeTooLowException();
}