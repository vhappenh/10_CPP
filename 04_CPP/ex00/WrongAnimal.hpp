/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:28:25 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/28 11:42:22 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	~WrongAnimal();

	std::string getType() const;
	void		setType(const std::string type);
	void		makeSound() const;
} ;