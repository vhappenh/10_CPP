/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:39:57 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/21 14:32:27 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ClapTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap trappy;
	ScavTrap scavvy("Charles");
	FragTrap fraggy("Eugene");
	std::cout << std::endl;
	trappy.attack("BadBoy");
	trappy.takeDamage(2);
	trappy.beRepaired(2);
	std::cout << std::endl;
	scavvy.attack("BadGirl");
	scavvy.takeDamage(2);
	scavvy.beRepaired(2);
	scavvy.guardGate();
	std::cout << std::endl;
	fraggy.attack("BadPeople");
	fraggy.takeDamage(2);
	fraggy.beRepaired(2);
	fraggy.highFivesGuys();
	std::cout << std::endl;
	return (0);
}