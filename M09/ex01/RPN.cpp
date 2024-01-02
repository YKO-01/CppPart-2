/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 01:42:25 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/02 01:14:45 by ayakoubi         ###   ########.fr       */
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

void copyStack(std::stack<int> *dst, std::stack<int> &src)
{
	dst->pop();
	if (arr.size())
		copyStack(dst, src);
	dst.push(src.top());
	src.pop();
}

PRN& RPN::operator = (const RPN& copy)
{
	std::stack<int> tmp;
	tmp = copy.arr
	if (arr.size())
		copyStack();
	else
	{

		
