/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:42:30 by vhappenh          #+#    #+#             */
/*   Updated: 2023/08/29 15:14:45 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Animal *animal[10];
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if(i < 5)
		{
			animal[i] = new Dog();
			std::cout << std::endl;
		}
		else
		{
			animal[i] = new Cat();
			std::cout << std::endl;
		}
	}
	for (int i = 0; i < 10; i++)
		animal[i]->makeSound();
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete animal[i];
		std::cout << std::endl;
	}
	return 0;
}