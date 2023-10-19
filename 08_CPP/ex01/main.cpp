/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:05:25 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/19 13:39:24 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void) {
	std::deque<int> deq;
	for (int i = 0; i < 10005; ++i) {
		deq.push_back(rand());
	}

	//wrong attempt with too many values
	std::cout << "----------first test----------\n";
	try {
		Span x(10000);
		x.addManyNumbers(deq.begin(), deq.end());
		std::cout << "shortest span: " << x.shortestSpan() << "\n";
		std::cout << "longest span:  " << x.longestSpan() << "\n";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	//wrong attempt with too little values
	std::cout << "----------second test----------\n";
	try {
		Span x(1);
		x.addNumber(1);
		std::cout << "shortest span: " << x.shortestSpan() << "\n";
		std::cout << "longest span:  " << x.longestSpan() << "\n";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	//proper attempt
	std::cout << "----------third test----------\n";
	try {
		Span x(10010);
		x.addManyNumbers(deq.begin(), deq.end());
		std::cout << "shortest span: " << x.shortestSpan() << "\n";
		std::cout << "longest span:  " << x.longestSpan() << "\n";
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