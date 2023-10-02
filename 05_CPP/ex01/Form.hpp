/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:14:26 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/02 15:07:16 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form {
private:
	const std::string 	_name;
	bool				_signed;
	const int			_sign;
	const int			_exec;
public:
	Form(std::string name, int sign, int exec);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	std::string		getName() const;
	bool			getStatus() const;
	int				getSign() const;
	int				getExec() const;
	void			beSigned(const Bureaucrat& other);
	
	class GradeTooHighException : public std::exception	{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception	{
	public:
		const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream &out, const Form& other);