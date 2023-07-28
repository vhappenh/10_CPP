/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:47:15 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/28 11:58:06 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;
public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();

	std::string getType() const;
	void		setType(const std::string type);
	void		makeSound() const;
} ;