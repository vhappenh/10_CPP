/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:45:41 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/15 09:38:53 by vhappenh         ###   ########.fr       */
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
} ;