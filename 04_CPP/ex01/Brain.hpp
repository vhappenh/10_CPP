/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:52:37 by vhappenh          #+#    #+#             */
/*   Updated: 2023/07/28 13:28:52 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	std::string getType(int i) const;
	void		setType(const std::string idea, int i);
} ;