/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:53:33 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/11 11:59:56 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:
	Weapon 		*weapon;
	std::string name;
public:
	HumanA(std::string name, Weapon weapon);
	~HumanA(void);
	void attack();
	void setType(std::string type);
} ;

#endif