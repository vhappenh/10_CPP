/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:35:44 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/02 13:51:54 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool	get_date(std::string line, std::tm& date) {
	std::string::iterator 	it;

	date.tm_year = std::atoi(line.c_str());
	line.erase(line.begin(), line.begin() + line.find('-') + 1);
	date.tm_mon = std::atoi(line.c_str());
	line.erase(line.begin(), line.begin() + line.find('-') + 1);
	date.tm_mday = std::atoi(line.c_str());
	return (false);
}

static bool	get_value(std::string line, int& value) {
	std::string::iterator it;
	
	for (it = line.begin(); it < line.end(); it++) {
		if (*it == ',') {
			it++;
			break ;
		}
	}
	if (it == line.end()) {
		std::cerr << "Invalid data input\n";
		return (true);
	}
	value = std::atoi(&(*it));
	return (false);
}

bool	exchange(char *filename) {
	std::ifstream 			file;
	std::string				line;
	std::map<time_t, int>	data;
	std::tm					raw_date;
	time_t					date;
	int						value;

	(void)filename;
	std::memset(&raw_date, 0, sizeof(raw_date));
	file.open("datatest.csv");
	if (file.is_open()) {
		std::getline(file, line);
		while (std::getline(file, line)) {
			if (get_date(line, raw_date)) {
				file.close();
				return (true);
			}
			if (get_value(line, value)) {
				file.close();
				return (true);
			}
			date = mktime(&raw_date);
			std::cout << value << std::endl;
			std::cout << date << std::endl;
			//data.insert({date, value});
		}
	}
	file.close();
	return (false);
}