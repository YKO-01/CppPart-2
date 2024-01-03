/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 01:42:25 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/04 00:34:03 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// __ Constructor & Destructor _________________________________________________
// =============================================================================
RPN::RPN()
{
}

RPN::RPN(const RPN& copy)
{
	*this = copy;
}

RPN::~RPN()
{
}

// __ Assignement operator _____________________________________________________
// =============================================================================
/*
void copyStack(std::deque<int> *dst, std::stack<int> &src)
{
	dst->pop();
	if (arr.size())
		copyStack(dst, src);
	dst.push(src.top());
	src.pop();
}
*/
RPN& RPN::operator = (const RPN& copy)
{
	arr = copy.arr;
	return (*this);
}

// __ Calculate() ______________________________________________________________
// =============================================================================
void	RPN::calculate(char *str, std::deque<int> &arr)
{
	char s[4] = {'+', '-', '/', '*'};
	int i = -1;
	int len;
	while (++i < 4)
		if (*str == s[i])
			break;
	if (*str++ && std::isdigit(*str))
		arr.posh_back(std::atoi(*str);
	len = arr.size()
	if (*str)
		calculte(str, arr);
	if (arr.size()
		pop_front()	
}
