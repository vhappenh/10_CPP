/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:35:44 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/02 18:48:34 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool	get_date(std::string line, std::tm& date) {
	size_t 	pos;

	/* general check */
	if (line.find_first_of(',') == std::string::npos) {
		std::cerr << "Invalid data input. No seperator!\n";
		return (true);
	}
	
	/* reading year and protection */
	date.tm_year = std::atoi(line.c_str());
	if (date.tm_year > 9999) {
		std::cerr << "Invalid data input. Date absurdly high!\n";
	}
	
	/* skipping to read month */
	pos = line.find('-');
	if (pos == std::string::npos || pos > 4) {
		std::cerr << "Invalid data input. Date config wrong!\n";
		return (true);
	}
	line.erase(line.begin(), line.begin() + pos + 1);
	date.tm_mon = std::atoi(line.c_str());
	
	/* skipping to read day */
	pos = line.find('-');
	if (pos == std::string::npos || pos > 2) {
		std::cerr << "Invalid data input. Date config wrong!\n";
		return (true);
	}
	line.erase(line.begin(), line.begin() + pos + 1);
	date.tm_mday = std::atoi(line.c_str());
	
	/* just for checking the values */
	// std::cout << "y: " << date.tm_year << std::endl;
	// std::cout << "m: " << date.tm_mon << std::endl;
	// std::cout << "d: " << date.tm_mday << std::endl;
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
			// std::cout << value << std::endl;
			// std::cout << date << std::endl;
			//data.insert({date, value});
		}
	}
	file.close();
	return (false);
}