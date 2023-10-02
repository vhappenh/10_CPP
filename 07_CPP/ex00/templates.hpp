/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyTemplateClass.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:24:15 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/20 14:06:28 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void swap(T& p1, T& p2){
	T swap;
	
	swap = p1;
	p1 = p2;
	p2 = swap;	
}

template <typename T>
T min(T p1, T p2){
	if (p2 <= p1)
		return (p2);
	else
		return (p1);
}

template <typename T>
T max(T p1, T p2){
	if (p2 >= p1)
		return (p2);
	else
		return (p1);
}