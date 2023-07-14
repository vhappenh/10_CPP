/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:52:51 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/14 12:55:22 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	complainer;
	std::string arr[5] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = -1;

	if (ac != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	std::string input = av[1];
    while (++i < 4)
	{
        if (input == arr[i])
            break ;
	}
	switch (i)
	{
		case 0 : complainer.complain("debug");
			;
		case 1 : complainer.complain("info");
			;
		case 2 : complainer.complain("warning");
			;
		case 3 : complainer.complain("error");
			break ;
		default : std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
    return (0);
}