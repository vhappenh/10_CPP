/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:14:26 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/07 14:43:35 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class AForm {
private:
	const std::string 	_name;
	bool				_signed;
	const int			_sign;
	const int			_exec;
public:
	AForm(std::string name, int sign, int exec);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	std::string		getName() const;
	bool			getStatus() const;
	int				getSign() const;
	int				getExec() const;
	void			beSigned(const Bureaucrat& other);
	
	virtual void	execute(Bureaucrat const & executor) const = 0;
	
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

std::ostream&	operator<<(std::ostream &out, const AForm& other);