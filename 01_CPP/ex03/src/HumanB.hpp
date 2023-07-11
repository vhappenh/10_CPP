/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:53:35 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/11 17:59:18 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private:
	Weapon 		*_weapon;
	std::string _name;
public:
	HumanB(std::string name);
	~HumanB(void);
	void attack();
	void setWeapon(Weapon &weapon);
} ;

#endif