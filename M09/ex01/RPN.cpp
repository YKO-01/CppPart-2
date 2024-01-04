/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 01:42:25 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/04 19:37:17 by ayakoubi         ###   ########.fr       */
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

int getValue(char c, int first, int second)
{
	if (c == '+')
		return (first + second);
	if (c == '-')
		return (first - second);
	if (c == '/')
		return (first / second);
	return (first * second);
}


int getOperator(char c)
{
	char s[4] = {'+', '-', '/', '*'};
	int i;

	i = -1;
	while (++i < 4)
		if (c == s[i])
			return (s[i]);
	return (-1);
}

// __ Calculate() ______________________________________________________________
// =============================================================================
void	RPN::calculate(char *str, int *ret)
{
	char s = 0;
	int len;
	int nbr[2];
	
	len = -1;
	while (*str && getOperator(*str) < 0)
	{
		if (std::isdigit(*str))
			arr.push_back(std::atoi(&(*str)));
		str++;
	}
	while (*str && (*str == ' '))
		str++;
	if (getOperator(*str) >= 0)
		s = getOperator(*str++);
	while (arr.size() && ++len < 2)
	{
		nbr[len] = arr.back();
		arr.pop_back();
	}
	*ret = getValue(s, nbr[1], nbr[0]);
	arr.push_back(*ret);
	if (*str && arr.size())
		calculate(str, ret);	
}
