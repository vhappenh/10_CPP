/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:52:01 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/09 12:16:35 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <stack>
#include <sstream>
#include <limits>

class RPN {
private:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();
public:
	static int	resolve(char *input);
} ;