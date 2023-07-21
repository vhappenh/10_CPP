/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:39:57 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/20 16:24:10 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap trappy("Boy");

	trappy.attack("BadBoy");
	trappy.takeDamage(2);
	trappy.beRepaired(2);
	trappy.beRepaired(2);
	trappy.beRepaired(2);
	trappy.beRepaired(2);
	trappy.beRepaired(2);
	trappy.beRepaired(2);
	trappy.beRepaired(2);
	trappy.beRepaired(2);
	trappy.beRepaired(2);
	trappy.beRepaired(2);
	trappy.beRepaired(2);
	trappy.beRepaired(2);
	trappy.takeDamage(2);
	trappy.attack("BadBoy");								
	return (0);
}