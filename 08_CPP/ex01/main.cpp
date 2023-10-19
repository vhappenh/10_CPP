/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:05:25 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/19 10:22:59 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void) {
	//wrong attempt with too many values
	try {
		Span x(10000);
		for (int i = 0; i < 10005; ++i) {
			x.addNumber(rand());
		}
		std::cout << "longest span:  " << x.longestSpan() << "\n";
		std::cout << "shortest span: " << x.shortestSpan() << "\n";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	//wrong attempt with too little values
	try {
		Span x(1);
		x.addNumber(1);
		std::cout << "longest span:  " << x.longestSpan() << "\n";
		std::cout << "shortest span: " << x.shortestSpan() << "\n";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	//proper attempt
	try {
		Span x(10000);
		for (int i = 0; i < 10000; ++i) {
			x.addNumber(rand());
		}
		std::cout << "longest span:  " << x.longestSpan() << "\n";
		std::cout << "shortest span: " << x.shortestSpan() << "\n";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	return (0);
}


// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }