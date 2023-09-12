/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:43:40 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/07 15:37:00 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>
#include <stdexcept>

class AForm ;

class Bureaucrat {
private:
	std::string _name;
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

	class GradeTooHighException : public std::exception	{
	public:
		const char* what() const throw() {
			return "Grade is too damn high!";
		}
	};
	class GradeTooLowException : public std::exception	{
	public:
		const char* what() const throw() {
			return "Grade is too damn low!";
		}
	};
};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat& other);