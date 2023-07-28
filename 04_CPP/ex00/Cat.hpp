/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:02:17 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/28 11:22:20 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	std::string getType() const;
	void		setType(const std::string type);
	void		makeSound() const;
} ;