/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:10:26 by vhappenh          #+#    #+#             */
/*   Updated: 2023/06/28 16:43:35 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	ft_eof(void)
{
	std::cout << std::endl << "Ctrl-D or EndOfFile detected." << std::endl;
	return (1);
}

int	main(void)
{
	Contact contact;
	PhoneBook phonebook;
	std::string str;
	std::string upper;
	int	i;
	bool limit;

	limit = false;	
	i = 0;
	while (1)
	{
		if (!std::cin.eof())
			std::cout << "What do you want to do? (ADD, SEARCH or EXIT)" << std::endl;
		std::getline (std::cin, str);
		if (std::cin.eof())
			return (ft_eof());
		for (int i = 0; str[i]; i++)
			upper += std::toupper(str[i]);
		if (upper == "ADD")
		{
			if (!contact.Add())
			{
				phonebook.Add(contact, i);
				i++;
				if (i == 8)
				{
					i = 0;
					limit = true;
				}
			}
		}
		else if (upper == "SEARCH")
		{
			if (limit)
				phonebook.Search(8);
			else
				phonebook.Search(i);
		}
		else if (upper == "EXIT")
		{
			contact.Exit();
			return (0);
		}
		else
			std::cout << "Wrong input. Please either add, search or exit." << std::endl;
		upper.clear();
	}
	return (0);
}