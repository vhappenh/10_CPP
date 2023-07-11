/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:53:35 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/11 11:46:48 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private:
	Weapon 		*weapon;
	std::string name;
public:
	HumanB(std::string name);
	~HumanB(void);
	void attack();
	void setType(std::string type);
	void setWeapon(Weapon weapon);
} ;

#endif