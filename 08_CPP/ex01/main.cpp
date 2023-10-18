/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:05:25 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/18 17:25:42 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void) {
	Span x(10000);

	for (int i = 0; i < 10000; ++i) {
		x.addNumber(rand());
	}
	x.printDeque();
	std::cout << "longest span:  " << x.longestSpan() << "\n";
	std::cout << "shortest span: " << x.shortestSpan() << "\n";
	return (0);
}

//	#include <time.h>
//	clock_t t = clock();
//	std::cout << (clock() - t) / (long double)CLOCKS_PER_SEC << "\n";

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