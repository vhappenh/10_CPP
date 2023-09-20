/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:43:40 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/20 10:25:06 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>

class AForm ;

class Bureaucrat {
private:
	const std::string _name;
	int			_grade;
public:
	Bureaucrat(std::string name = "default", int grade = 0);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	std::string		getName() const;
	int				getGrade() const;
	void			incrementGrade();
	void			decrementGrade();
	void			signForm(const AForm& other);
	void 			executeForm(AForm const & form);

	class GradeTooHighException : public std::exception	{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception	{
	public:
		const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat& other);