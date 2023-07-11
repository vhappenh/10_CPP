/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:16:28 by vhappenh          #+#    #+#             */
/*   Updated: 2023/06/28 10:04:42 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(void) {}

bool	ft_check_input(std::string input)
{
	int detector;
	
	detector = 0;
	if (input.empty())
	{
		std::cout << "Empty input!" << std::endl;
		return (true);
	}
	for (int i = 0; input[i]; i++)
	{
		if (input[i] == ' ')
			detector++;
		else if (input[i] == '	')
			detector++;
		else
			return (false);
	}
	if (detector == (int)input.length())
	{
		std::cout << "Space or tab not allowed!" << std::endl;
		return (true);
	}
	return (false);
}

std::string Contact::get_private(int i) const
{
	if (i == FIRST_NAME)
		return (this->_first_name);
	if (i == LAST_NAME)
		return (this->_last_name);
	if (i == NICKNAME)
		return (this->_nickname);
	if (i == NUMBER)
		return (this->_number);
	if (i == SECRET)
		return (this->_secret);
	return NULL;
}

std::string get_contact(std::string prompt)
{
	int i;
	std::string input;

	i = 0;
	while (1)
	{	
		std::cout << prompt;
		std::getline (std::cin, input);
		if (!ft_check_input(input))
			break ;
		if (std::cin.eof())
			return (std::string());
		i++;
		if (i == 3)
		{
			std::cout << "Too many wrong inputs!" << std::endl;
			return (std::string());
		}
	}
	return (input);	
}

int Contact::Add(void)
{
	this->_first_name = get_contact("Enter name: ");
	if (this->_first_name.empty())
		return (1);
	_last_name = get_contact("Enter surname: ");
	if (_last_name.empty())
		return (1);
	_nickname = get_contact("Enter nickname: ");
	if (_nickname.empty())
		return (1);
	_number = get_contact("Enter phonenumber: ");
	if (_number.empty())
		return (1);
	_secret = get_contact("Enter darkest secret: ");
	if (_secret.empty())
		return (1);
	std::cout << "Adding to phonebook..." << std::endl;
	return (0);
}

void Contact::Exit(void)
{
	std::cout << "Exiting phonebook..." << std::endl;
}

Contact::~Contact(void) {}