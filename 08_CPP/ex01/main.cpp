/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:05:25 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/17 15:51:22 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"	

int	main(void) {
	Span x(10);

	x.addNumber(3);
	x.addNumber(0);
	x.addNumber(100);
	x.addNumber(-1);
	x.printDeque();
	return (0);
}