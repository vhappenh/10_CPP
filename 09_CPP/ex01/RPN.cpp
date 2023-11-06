/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:52:03 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/06 14:21:28 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& other) {(void)other;}
RPN& RPN::operator=(const RPN& other) {(void)other; return (*this);}
RPN::~RPN() {}

static bool	isoperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

//TODO adapt the int n[] so that is adaptable for different inputs where I can have more than 3 numbers stored at once
int		RPN::resolve(char *input) {
	std::stack<std::string> todo;
	int						r;
	int						n[2];
	char				 	op;
		
	for (int i = 0; input[i]; i++) {
		//filling the stack with input
		if ((isdigit(input[i]) || isoperator(input[i])) && (input[i + 1] == ' ' || !input[i + 1]))
			todo.push(std::string(1, input[i]));
		else if (input[i] == ' ')
			;
		else
			throw std::logic_error("Error while creating stack\n");
			
		//checking and handling if operations are doable
		if (todo.size() >= 3) {
			
			if (todo.top().c_str()[0] == '+' || todo.top().c_str()[0] == '-' || todo.top().c_str()[0] == '*' || todo.top().c_str()[0] == '/') {
				op = todo.top().c_str()[0];
				todo.pop();
				n[0] = std::atoi(todo.top().c_str());
				todo.pop();
				n[1] = std::atoi(todo.top().c_str());
				todo.pop();
				
				if (op == '+')
					r = n[0] + n[1];
				else if (op == '-')
					r = n[1] - n[0];
				else if (op == '*')
					r = n[0] * n[1];
				else
					r = n[1] / n[0];

				std::stringstream ss;
				ss << r;
				todo.push(ss.str());
			}
			else if (isdigit(todo.top().c_str()[0]))
				;
			else {	
				throw std::logic_error("Error while resolving stack\n");
			}
		}
	}	
	return (std::atoi(todo.top().c_str()));
}