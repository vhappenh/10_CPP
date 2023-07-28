/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:42:30 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/28 14:58:25 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	Animal animal[10];
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if(i < 5)
		{
			animal[i] = Dog();
			std::cout << std::endl;
		}
		else
		{
			animal[i] = Cat();
			std::cout << std::endl;
		}
	}
	return 0;
}