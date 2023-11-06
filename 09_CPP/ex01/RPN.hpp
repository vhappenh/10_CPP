/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:52:01 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/06 13:49:39 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <stack>
#include <sstream>

class RPN {
private:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();
public:
	static int	resolve(char *input);
} ;