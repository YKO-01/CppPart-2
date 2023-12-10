/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:37:43 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/10 11:52:37 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// __ Constructors & Destructor ________________________________________________
// =============================================================================
Span::Span()
{
}

Span::Span(unsigned int n) : N(n)
{
}

Span::Span(const Span& copy)
{
	this->N = copy.N;
	*this = copy;
}

Span::~Span()
{ 
	this->numbers.clear();
}

// __ Assignement Operator _____________________________________________________
// =============================================================================
Span&	Span::operator = (const Span& copy)
{
	try
	{
		unsigned int	i;
		i = -1;
		this->numbers.clear();
		while (++i < copy.numbers.size())
		{
			if (this->N < i)
				throw "its index is out of bounds";
			this->numbers.push_back(copy.numbers[i]);
		}
	}
	catch (const char* str)
	{
		std::cout << str << std::endl;
	}
	return (*this);
}

// __ Add Number To Span _______________________________________________________
// =============================================================================
void	Span::addNumber(int nbr)
{
	try
	{
		std::vector<int>::iterator itr;
		itr = std::find(numbers.begin(), numbers.end(), nbr);
		if (itr != numbers.end())
			throw "this number exists";
		if (numbers.size() < N)
			numbers.push_back(nbr);
		else
			throw "its index is out of bounds";
	}
	catch (const char* str)
	{
		std::cout << str << " you can't add this number " << nbr << std::endl;
	}
}

// __ Shortest Span ____________________________________________________________
// =============================================================================
int	Span::shortestSpan()
{
	try
	{
		if (numbers.size() <= 1)
			throw "There are not enough numbers to do this";
		std::vector<int> tmp;
		tmp = numbers;
		std::vector<int>::iterator first = tmp.begin();
		std::vector<int>::iterator last = tmp.end();
		std::sort(first, last);
		unsigned int i;
		int shortest = *(last - 1) - *first;
		i = -1;
		while (++i < tmp.size() - 1)
		{
			if (*(first + 1) - *first < shortest)
				shortest = *(first + 1) - *first;
			first++;
		}
		return (shortest);
	}
	catch (const char* str)
	{
		std::cout << str << std::endl;
	}
	return (false);
}

// __ Longest Span ____________________________________________________________
// =============================================================================
int	Span::longestSpan()
{
	try
	{
		if (numbers.size() <= 1)
			throw "There are not enough numbers to do this";
		std::vector<int> tmp;
		tmp = numbers;
		std::vector<int>::iterator first = tmp.begin();
		std::vector<int>::iterator last = tmp.end();
		std::sort(first, last);
		int longest = *(last - 1) - *first;
		return (tmp.clear(), longest);
	}
	catch (const char* str)
	{
		std::cout << str << std::endl;
	}
	return (false);
}
