/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:36:32 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/11 18:39:45 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Wrong ammount of arguments" << std::endl;
        return (1);
    }
    std::string filename = av[1];
    std::string str1 = av[2];
    std::string str2 = av[3];
    std::cout << filename << std::endl;
    std::cout << str1 << " " << str2 << std::endl;
}