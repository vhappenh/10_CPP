/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:32:15 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/28 11:36:58 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	~Animal();

	virtual std::string getType() const;
	void		setType(const std::string type);
	virtual void		makeSound() const;
} ;