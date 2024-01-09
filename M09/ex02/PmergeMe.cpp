/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:42:39 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/09 10:02:42 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// __ Constructurs _____________________________________________________________
// =============================================================================
PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char **arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		vec.push_back(std::atoi(arg[i]));
}

// __ Copy Constructure ________________________________________________________
// =============================================================================
PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
}

// __ Destructure ______________________________________________________________
// =============================================================================
PmergeMe::~PmergeMe()
{
}

// __ Asignement Operator ______________________________________________________
// =============================================================================
PmergeMe& PmergeMe::operator = (const PmergeMe& copy)
{
	this->vec = copy.vec;
	this->dvec = copy.dvec;
	this->main_chain = copy.main_chain;
	return (*this);
}

// __ Asignement Operator ______________________________________________________
// =============================================================================
void	PmergeMe::initVectors()
{
	std::vector<int>::iterator	it = vec.begin();
	vector::iterator it2;
	it2 = vec.begin();
	while (it2 != vec.end())
	{
		std::cout << *it2 << std::endl;
		it2++;
	}

	fillDVector(it);
	it = vec.begin();
	printVector();
	while (dvec.size() > 3)
		createPair();
}

// __ Asignement Operator ______________________________________________________
// =============================================================================
void	PmergeMe::createPair()
{
	vector::iterator it;
	dvector::iterator dit;
	dvector::iterator tmp;
	size_t i;

	dit = dvec.begin();
	while (dit != dvec.end())
	{
		i = -1;
		it = dit->begin();
		if (dit != dvec.end() - 1)
		{
			tmp = dit + 1;
			if (*(dit->end() - 1) <= *(tmp->end() - 1))
				dit->insert(dit->end(), tmp->begin(), tmp->end());
			else
				dit->insert(dit->begin(), tmp->begin(), tmp->end());
			tmp->erase(tmp->begin(), tmp->end());
			dvec.erase(tmp);
		}
		dit++;
	}
	printVector();
}

// __ Asignement Operator ______________________________________________________
// =============================================================================
void	PmergeMe::printVector()
{
	vector::iterator it;
	dvector::iterator dit;

	std::cout << "====== Vector 2 ===========" << std::endl;
	dit = dvec.begin();
	while (dit != dvec.end())
	{
		std::cout << "this vec" << std::endl;
		it = dit->begin();		
		while (it != dit->end())
		{
			std::cout << *it << std::endl;
			it++;
		}
		dit++;
	}
}


// __ Fill DVector _____________________________________________________________
// =============================================================================
void	PmergeMe::fillDVector(std::vector<int>::iterator it)
{
	std::vector<int> tmp;
	tmp.push_back(*it);
	dvec.push_back(tmp);
	if (it != vec.end() - 1)
		fillDVector(++it);
	vec.pop_back();
}

