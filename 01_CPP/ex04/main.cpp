/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:36:32 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/11 18:56:53 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Wrong ammount of arguments" << std::endl;
        return (1);
    }
    const std::string filename = av[1];
    std::string str1 = av[2];
    std::string str2 = av[3];
    std::string line;
    std::ifstream readfile;
    readfile.open(filename);
    if (readfile.is_open())
    {
        while (std::getline (readfile, line))
            std::cout << line << std::endl;
        readfile.close();
    }
    else
        std::cout << "Error when opening readfile" << std::endl;
    //std::ofstream writefile;
}