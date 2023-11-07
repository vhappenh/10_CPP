/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:35:44 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/07 15:32:24 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool	get_date(std::string line, std::tm& date, char c) {
	size_t 	pos;
	size_t	found;
	
	/* general checks */
	if (line.find_first_of(c) == std::string::npos) {
		std::cerr << "Invalid data input. No seperator!\n";
		return (true);
	}
	found = line.find_first_not_of("0123456789.-|, ");
	if (found != std::string::npos) {
		std::cerr << "Invalid data input. Invalid character!\n";
		return (true);
	}
	
	/* reading year and protection */
	date.tm_year = std::atoi(line.c_str());
	if (date.tm_year > 9999 || date.tm_year < 2009) {
		std::cerr << "Invalid data input. Year out of range!\n";
		return (true);
	}
	
	/* skipping to read month */
	pos = line.find('-');
	if (pos == std::string::npos || pos > 4) {
		std::cerr << "Invalid data input. Date config wrong!\n";
		return (true);
	}
	line.erase(line.begin(), line.begin() + pos + 1);
	date.tm_mon = std::atoi(line.c_str()) - 1;
	
	/* skipping to read day */
	pos = line.find('-');
	if (pos == std::string::npos || pos > 2) {
		std::cerr << "Invalid data input. Date config wrong!\n";
		return (true);
	}
	line.erase(line.begin(), line.begin() + pos + 1);
	date.tm_mday = std::atoi(line.c_str());
	return (false);
}

static bool	get_value(std::string line, float& value, char c) {
	std::string::iterator it;
	
	for (it = line.begin(); it < line.end(); it++) {
		if (*it == c) {
			it++;
			break ;
		}
	}
	if (*it == ' ')
		it++;
	if (line.find_first_of('.') != line.find_last_of('.')) {
		std::cerr << "Invalid value input. Format after seperator wrong!\n";
		return (true);		
	}
	else if (isdigit(*it))
		value = std::atof(&(*it));
	else {
		std::cerr << "Invalid value input. Format after seperator wrong!\n";
		return (true);
	}
	return (false);
}

static bool	compare_dates(std::tm one, std::tm two) {
	if (one.tm_year != two.tm_year || one.tm_mon != two.tm_mon || one.tm_mday != two.tm_mday)
		return (true);
	return (false);
}

static bool	fill_map(std::map<time_t, float>& data) {
	std::ifstream 			file;
	std::string				line;
	std::tm					raw_date;
	std::tm					check_date;
	time_t					date;
	float					value;

	std::memset(&raw_date, 0, sizeof(raw_date));
	std::memset(&check_date, 0, sizeof(check_date));
	file.open("data.csv");
	if (file.is_open()) {
		while (std::getline(file, line)) {
			if (line == "date,exchange_rate")
				std::getline(file, line);
			if (get_date(line, raw_date, ',') || get_date(line, check_date, ',')) {
				file.close();
				return (true);
			}
			date = mktime(&raw_date);
			if (compare_dates(raw_date, check_date)) {
				std::cerr << "Invalid data input. Wrong date!\n";
				file.close();
				return (true);
			}
			if (get_value(line, value, ',')) {
				file.close();
				return (true);
			}
			data.insert(std::make_pair(date, value));
		}
		file.close();
	}
	if (data.empty()) {
		std::cerr << "Invalid data input. Empty file!\n";
		return (true);
	}
	return (false);
}

static bool	check_and_compare_input(char *filename, std::map<time_t, float> data) {
	std::ifstream 			file;
	std::string				line;
	std::tm					raw_date;
	std::tm					check_date;
	time_t					date;
	float					value;

	std::memset(&raw_date, 0, sizeof(raw_date));
	std::memset(&check_date, 0, sizeof(check_date));
	file.open(filename);
	if (file.is_open()) {
		while (std::getline(file, line)) {
			if (line == "date | value")
				std::getline(file, line);
			if (!get_date(line, raw_date, '|')) {
				get_date(line, check_date, '|');
				date = mktime(&raw_date);
				if (compare_dates(raw_date, check_date))
					std::cerr << "Invalid data input. Wrong date!\n";
				else {
					if (!get_value(line, value, '|')) {
						if (value < 0 || value > 1000)
							std::cerr << "Invalid value input. Wrong btc amount!\n";
						else {
							std::map<time_t, float>::iterator it = data.find(date);
							if (it != data.end())
								std::cout << line << " = " << it->second * value << "\n";
							else {
								std::map<time_t, float>::iterator lb = data.lower_bound(date);
								if (lb != data.begin()) {
									lb--;	
									std::cout << line << " = " << lb->second * value << "\n";	
								}
								else
									std::cout << "No date or smaller date found!\n";	
								
							}
						}
					}	
				}
			}
		}
		file.close();
	}
	return (false);
}

bool	exchange(char *filename) {
	std::map<time_t, float>	data;

	if (fill_map(data))
		return (true);
	if (check_and_compare_input(filename, data))
		return (true);
	return (false);
}