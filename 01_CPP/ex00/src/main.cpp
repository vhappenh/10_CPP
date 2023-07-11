/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:24:07 by vhappenh          #+#    #+#             */
/*   Updated: 2023/06/28 13:43:53 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie *newzombo;

	newzombo = newZombie("Peter");
	randomChump("Liam");
	newzombo->announce();
	delete (newzombo);
	return (0);
}