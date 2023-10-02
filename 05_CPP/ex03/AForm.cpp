/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:14:24 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/07 15:06:48 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int sign, int exec) : _name(name), _signed(false), _sign(sign), _exec(exec) {
	std::cout << "AForm constructor called!" << std::endl;
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
	else if (sign < 1 || exec < 1)
		throw GradeTooHighException();	
}

AForm::AForm(const AForm& other) : _name(other._name), _sign(other._sign), _exec(other._exec) {
	std::cout << "AForm copy constructor called!" << std::endl;
	*this = other;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

AForm::~AForm() {
	std::cout << "AForm destructor called!" << std::endl;
}

std::string	AForm::getName() const {
	return(_name);
}

bool	AForm::getStatus() const {
	return (_signed);
}

int		AForm::getSign() const {
	return (_sign);
}

int		AForm::getExec() const {
	return (_exec);
}

void	AForm::beSigned(const Bureaucrat& other){
	if (other.getGrade() <= getSign())
		_signed = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too damn high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too damn low!";
}

std::ostream&	operator<<(std::ostream &out, const AForm& other) {
	out << other.getName();
	out << ", AForm sign ";
	out << other.getSign();
	out << ", AForm execute ";
	out << other.getExec();
	return out;
}

void	AForm::execute(Bureaucrat const & executor) const {
	(void) executor;
	return ;
}