/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:43:38 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/06 16:12:06 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat constructor called!" << std::endl;
	if (grade <= 150 && grade >= 1)
		_grade = grade;
	else if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();	
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	std::cout << "Bereaucrat copy constructor called!" << std::endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bereaucrat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called!" << std::endl;
}

std::string	Bureaucrat::getName() const {
	return(_name);
}

int	Bureaucrat::getGrade() const {
	return (_grade);
}

void	Bureaucrat::incrementGrade() {
		if (_grade - 1 >=  1)
			_grade--;
		else
			throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade() {
		if (_grade + 1 <=  150)
			_grade++;
		else
			throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream &out, const Bureaucrat& other) {
	out << other.getName();
	out << ", bureaucrat grade ";
	out << other.getGrade();
	return out;
}