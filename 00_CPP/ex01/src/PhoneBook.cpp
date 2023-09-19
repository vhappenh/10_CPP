/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:16:37 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/19 15:54:47 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void) {}

void PhoneBook::Add(Contact contact, int i)
{
	_storage[i] = contact;
}

bool check_input(std::string input)
{
	bool error;

	error = false;
	if (input.empty())
	{
		std::cout << "Empty input!" << std::endl;
		return (true);
	}
	if (input.find_last_not_of("01234567") != std::string::npos)
	{
		std::cout << "Wrong digit input!" << std::endl;
		return (true);
	}
	if (!(input[0] >= '0' && input[0] <= '7'))
	{
		std::cout << "Wrong digit input!" << std::endl;
		return (true);
	}
	if (input[1])
	{
		std::cout << "Too many numbers!" << std::endl;
		return (true);
	}
	return (false);
}

void search_print(Contact _storage, int i)
{
	if (_storage.get_private(i).length() > 10)
		std::cout << std::setw(9) << std::right << _storage.get_private(i).substr(0, 9) << ".";
	else if (_storage.get_private(i).length() == 10)
		std::cout << std::setw(10) << std::right << _storage.get_private(i);
	else
		std::cout << std::setw(10) << std::right << _storage.get_private(i);
	std::cout << "|";
}

void PhoneBook::Search(int n)
{
	std::string index;
	int i;
	
	if (n == 0)
	{
		std::cout << "No contacts yet!" << std::endl;
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << std::setw(10) << std::right << i;
		std::cout << "|";
		search_print(_storage[i], FIRST_NAME);
		search_print(_storage[i], LAST_NAME);
		search_print(_storage[i], NICKNAME);
		std::cout << std::endl;
	}
	
	i = 0;
	while (1)
	{
		std::cout << "Enter index you want to see: ";
		std::getline (std::cin, index);
		if (!check_input(index))
		{
			if ((index[0] - 48) < n)
			{
				std::cout << _storage[(int)index[0] - 48].get_private(FIRST_NAME) << std::endl;
				std::cout << _storage[(int)index[0] - 48].get_private(LAST_NAME) << std::endl;
				std::cout << _storage[(int)index[0] - 48].get_private(NICKNAME) << std::endl;
				std::cout << _storage[(int)index[0] - 48].get_private(NUMBER) << std::endl;
				std::cout << _storage[(int)index[0] - 48].get_private(SECRET) << std::endl;
				break ;
			}
			else
				std::cout << "Please use existing index!" << std::endl;
		}
		i++;
		if ( i == 3)
		{
			std::cout << "Too many wrong attempts!" << std::endl;
			return ;
		}
		if (std::cin.eof())
			return ;	
	}
	return ;
}

PhoneBook::~PhoneBook(void) {}