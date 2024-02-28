/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 01:42:25 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/02/25 04:28:19 by ayakoubi         ###   ########.fr       */
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
RPN& RPN::operator = (const RPN& copy)
{
	arr = copy.arr;
	return (*this);
}

// __ getValue() _______________________________________________________________
// =============================================================================
int	RPN::getValue(char c, int first, int second)
{
	if (c == '+')
		return (first + second);
	if (c == '-')
		return (first - second);
	if (c == '/')
	{
		if (second == 0)
			throw MyException("you can't divide by 0"); 
		return (first / second);
	}
	return (first * second);
}

// __ get Operator _____________________________________________________________
// =============================================================================
int RPN::getOperator(char c)
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
	{
		if (arr.size() < 2)
			throw MyException("Error");
		s = getOperator(*str++);
	}
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
