/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:52:03 by vhappenh          #+#    #+#             */
/*   Updated: 2023/11/28 18:36:18 by vhappenh         ###   ########.fr       */
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
int	RPN::resolve(char *input) {
	std::stack<std::string> todo;
	double					r;
	double					n[2];
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
		if (todo.size() && (todo.top().c_str()[0] == '+' || (todo.top().c_str()[0] == '-' && !isdigit(todo.top().c_str()[1])) || todo.top().c_str()[0] == '*' || todo.top().c_str()[0] == '/')) {
			op = todo.top().c_str()[0];
			todo.pop();
			if (todo.size()) {
				n[0] = std::strtod(todo.top().c_str(), NULL);
				todo.pop();
			}
			else
				throw std::logic_error("Error while resolving stack\n");
			if (todo.size()) {
				n[1] = std::strtod(todo.top().c_str(), NULL);
				todo.pop();
			}
			else
				throw std::logic_error("Error while resolving stack\n");			
			if (op == '+')
				r = n[0] + n[1];
			else if (op == '-')
				r = n[1] - n[0];
			else if (op == '*')
				r = n[0] * n[1];
			else {
				if (n[0] == 0)
					throw std::runtime_error("Division by 0 invalid. Undefined behaviour expected\n");
				r = n[1] / n[0];
			}

			std::stringstream ss;
			if (r <= std::numeric_limits<int>::min() || r >= std::numeric_limits<int>::max())
				throw std::runtime_error("Error while resolving stack. Out of int range\n");
			ss << r;
			todo.push(ss.str());
		}
		else if (!todo.size())
			;
		else if (isdigit(todo.top().c_str()[0]) || (todo.top().c_str()[0] == '-' && isdigit(todo.top().c_str()[1])))
			;
		else {	
			throw std::logic_error("Error while resolving stack\n");
		}
	}
	if (todo.size() == 1)
		return (std::strtod(todo.top().c_str(), NULL));
	else
		throw std::logic_error("Could not resolve stack\n");
}