/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:15:25 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/19 15:13:01 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base*	generate(void){
	unsigned int i = rand() % 3;
	switch(i){
		case 0: {
				std::cout << "A" << std::endl;
				return (new A);
			}
		case 1: {
				std::cout << "B" << std::endl;
				return (new B);
			}
		default: {
				std::cout << "C" << std::endl;
				return (new C);
			}
		
	}
}

void	identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown type" << std::endl;		
}

void	identify(Base& p){
	if (dynamic_cast<const A*>(&p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<const B*>(&p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<const C*>(&p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "unknown type" << std::endl;
    }
}

int	main(void){
	srand(time(0));
	std::cout << "-------------------generate-------------------" << std::endl;
	Base *test1 = generate();
	Base *test2 = generate();
	Base *test3 = generate();
	Base *test4 = generate();
	Base *test5 = new Base;
	std::cout << "---------------identify pointer---------------" << std::endl;
	identify(test1);
	identify(test2);
	identify(test3);
	identify(test4);
	identify(test5);
	std::cout << "--------------identify reference--------------" << std::endl;
	identify(*test1);
	identify(*test2);
	identify(*test3);
	identify(*test4);	
	identify(*test5);	
	return (0);
}