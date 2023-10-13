/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:24:15 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/13 14:55:28 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename E>
void print_element(E& element) {
	std::cout << element << " | ";
}

template <typename E>
void increment_element(E& element) {
	element++;
}

template <typename T, typename F>
void iter(T* arr, size_t length, F function){
	for (size_t i = 0; i < length; i++)
		function(arr[i]);
	return ;
}