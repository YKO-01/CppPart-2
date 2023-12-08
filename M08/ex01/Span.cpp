/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:37:43 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/08 21:24:35 by ayakoubi         ###   ########.fr       */
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
	this->N = copy.N;
	int	i;
	i = -1;
	this->numbers.clear();
	while (++i < (int)copy.numbers.size())
		this->numbers.push_back(copy.numbers[i]);
	return (*this);
}

// __ Throw Exception __________________________________________________________
// =============================================================================
const char* Span::throwException::what() const throw()
{
	return ("its index is out of bounds");
}

// __ Add Number To Span _______________________________________________________
// =============================================================================
void	Span::addNumber(int nbr)
{
	if (numbers.size() < N)
		numbers.push_back(nbr);
	else
		throw throwException();
}

// __ Shortest Span ____________________________________________________________
// =============================================================================
int	Span::longestSpan()
{
	std::vector<int>::iterator first = numbers.begin();
	std::vector<int>::iterator last = numbers.end();

	int i;
	int max;
	int min;
	max = *first;
	min = *first;
	
	i = -1;
	while (*first != *(last - 1))
	{
		if (*first > *(first + 1) && max < *first)
			max = *first;
		if (*first < *(first + 1) && min > *first)
			min = *first;
		first++;
	}
	std::cout << max << " " << min << std::endl;
	return (max - min);
}


void	Span::printVector()
{
	int i;
	
	 i = -1;
	while (++i < (int)numbers.size())
	{
		std::cout << numbers[i] << std::endl;
	}
};

