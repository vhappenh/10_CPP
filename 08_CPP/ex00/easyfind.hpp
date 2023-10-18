/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:40:02 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/18 16:10:25 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <deque>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& cont, int n) {
	typename T::iterator it = std::find(cont.begin(), cont.end(), n);
	
	if (it != cont.end())
		return (it);
	else
		throw std::out_of_range("Element not found");
}