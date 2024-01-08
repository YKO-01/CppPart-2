/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:42:39 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/08 21:35:25 by ayakoubi         ###   ########.fr       */
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

void	PmergeMe::initVectors()
{
	std::vector<int>::iterator	it = vec.begin();
	fillDVector(it);
	it = vec.begin();
//	dvector::iterator it2 = dvec.begin();
/*	size_t j;
	size_t i;
	i = -1;
	size_t size = dvec.size();
	while (++i < size)
	{
		j = -1;
		while (++j < dvec[i].size())
			std::cout << dvec[i][j] << std::endl;
	}*/
	createPair();
}

void	PmergeMe::createPair()
{
	vector::iterator it;
	dvector::iterator dit;
	size_t i;

	dit = dvec.begin();
	while (dit != dvec.end())
	{
		i = -1;
		it = dit->begin();
		while (it != dit->end())
		{
			while (++i < 2)
			{
				dit->insert(*it, dit->
				std::cout << *it << std::endl;
			}
			it++;
		}
		dit++;
	}
}

void	PmergeMe::printVector()
{
	std::cout << "====== Vector 2 ===========" << std::endl;
	size_t i;
	std::vector<int>::iterator	it1 = vec.begin();
	i = -1;
	while (++i < vec.size())
	{
		std::cout << *it1 << std::endl;
		it1++;
	}
}


// __ Fill DVector _____________________________________________________________
// =============================================================================
void	PmergeMe::fillDVector(std::vector<int>::iterator it)
{
	std::vector<int> tmp;
	tmp.push_back(*it);
	dvec.push_back(tmp);
	if (it != vec.end())
		fillDVector(++it);
	//vec.pop_back();
}

