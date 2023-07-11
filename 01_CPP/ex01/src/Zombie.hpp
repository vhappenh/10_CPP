/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:47:42 by vhappenh          #+#    #+#             */
/*   Updated: 2023/06/28 14:17:22 by vhappenh         ###   ########.fr       */
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
	void set_name (std::string name);
} ;

Zombie* zombieHorde( int N, std::string name );

#endif