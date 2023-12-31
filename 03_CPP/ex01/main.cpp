/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:39:57 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/21 14:26:44 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap trappy;
	ScavTrap scavvy("Charles");

	trappy.attack("BadBoy");
	trappy.takeDamage(2);
	trappy.beRepaired(2);
	scavvy.attack("BadGirl");
	scavvy.takeDamage(2);
	scavvy.beRepaired(2);
	scavvy.guardGate();					
	return (0);
}