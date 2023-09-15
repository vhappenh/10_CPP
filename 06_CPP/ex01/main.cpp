/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:42:43 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/15 09:51:50 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void) {
	Data *lol = new Data();
	uintptr_t yolo = Serializer::serialize(lol);
	Data *blub = Serializer::deserialize(yolo);


	std::cout << lol << std::endl;
	std::cout << blub << std::endl;
	if (lol == blub)
		std::cout << "noice" << std::endl;
	else
		std::cout << "sadge" << std::endl;
}