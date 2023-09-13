/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:00:06 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/13 10:12:19 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm::AForm("SchrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm::AForm("SchrubberyCreationForm", 145, 137), _target(other._target) {
	std::cout << "ShrubberyCreationForm copy constructor called!" << std::endl;
	*this = other;
	return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &other) {
        _target = other._target;
    }
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called!" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget() const {
	return (_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (getExec() >= executor.getGrade()) {
		std::ofstream myfile;
		myfile.open ((_target + "_shrubbery").c_str());
		myfile << "~~~~~A~~~~~" << std::endl;
		myfile << "~~~~AAA~~~~" << std::endl;
		myfile << "~~~AAAAA~~~" << std::endl;
		myfile << "~~AAAAAAA~~" << std::endl;
		myfile << "~AAAAAAAAA~" << std::endl;
		myfile << "~~~~~H~~~~~" << std::endl;
	}
	else
		throw GradeTooLowException();
}