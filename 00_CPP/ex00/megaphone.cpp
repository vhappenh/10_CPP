/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:13:43 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/07 11:00:02 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cctype>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		std::string str;
		for (int i = 1; av[i]; i++)
			str += av[i];
		std::string::iterator i;
		for (i = str.begin(); i != str.end(); i++)
			std::cout << (char)toupper(*i);	
	}
	std::cout << std::endl;
	return (0);
}