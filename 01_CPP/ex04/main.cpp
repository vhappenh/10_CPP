/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:36:32 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/12 13:53:41 by vhappenh         ###   ########.fr       */
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
    
    const char      *filename = av[1];
    std::string     str1 = av[2];
    std::string     str2 = av[3];
    std::string     line;
    std::ifstream   readfile;
    std::ofstream   writefile;
    size_t          pos = 0;

    readfile.open(filename);
    writefile.open("newfile");
    if (readfile.is_open())
    {
        while (std::getline (readfile, line))
		{
			pos = 0;
			if (writefile.is_open())
			{
				while (pos < line.length() - 1)
				{
					pos = line.find(str1, pos);
					if (pos != 0 && !(pos > line.length()))
					{
						line.erase(pos, str1.length());
						line.insert(pos, str2);
						pos += str2.length();
					}
				}
				writefile << line << std::endl;
			}
		}
        readfile.close();
		writefile.close();
    }
    else
    {
        std::cout << "Error when opening readfile" << std::endl;
        return (1);
    }
    return (0);
}