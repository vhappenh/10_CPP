/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:32:15 by vhappenh          #+#    #+#             */
/*   Updated: 2023/08/29 15:04:05 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal(std::string name = "default");
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	std::string 	getType() const;
	virtual void	makeSound() const = 0;
} ;