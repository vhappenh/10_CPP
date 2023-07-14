/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:52:51 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/14 10:43:34 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(void)
{
	void (Harl::* ptfptr) (std::string) = &Harl::complain;
	Harl	complainer;
	
	(complainer.*ptfptr) ((std::string)"debug");
	(complainer.*ptfptr) ((std::string)"info");
	(complainer.*ptfptr) ((std::string)"warning");
	(complainer.*ptfptr) ((std::string)"error");
    return (0);
}