/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:39:57 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/25 15:56:51 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ClapTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap trappy;
	ScavTrap scavvy("Charles");
	FragTrap fraggy("Eugene");
	DiamondTrap diammy("Hans");
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
	diammy.attack("BadPeople");
	diammy.takeDamage(2);
	diammy.beRepaired(2);
	diammy.highFivesGuys();
	diammy.whoAmI();
	std::cout << std::endl;
	return (0);
}