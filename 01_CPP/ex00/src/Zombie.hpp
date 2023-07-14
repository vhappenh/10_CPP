/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:05:18 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/14 13:05:55 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie 
{
private:
	std::string name;
public:
	Zombie (std::string name = "Bob");
	~Zombie (void);
	void announce (void);
} ;

Zombie* newZombie( std::string name );
void 	randomChump( std::string name );

#endif