/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:52:51 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/14 12:53:41 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(void)
{
	Harl	complainer;
	
	complainer.complain("debug");
	complainer.complain("info");
	complainer.complain("warning");
	complainer.complain("error");
    return (0);
}