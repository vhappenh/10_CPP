/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:45:41 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/03 14:26:26 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Data {
private:
	const std::string _name;
public:
	Data();
	Data(const Data& other);
	Data& operator=(const Data& other);
	~Data();

	std::string getName();
} ;