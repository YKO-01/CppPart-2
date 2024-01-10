/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:42:39 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/10 11:47:11 by ayakoubi         ###   ########.fr       */
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
	this->mainChain = copy.mainChain;
	return (*this);
}

// __ Asignement Operator ______________________________________________________
// =============================================================================
void	PmergeMe::initVectors()
{
	std::vector<int>::iterator	it = vec.begin();
	dvector::iterator it2;
	dvector::iterator tmp;

	fillDVector(it);
	it = vec.begin();
	printVector(dvec);
	tmp = it2 + 1;
	it2 = dvec.begin();
	insertion(it2);
	while (it2 != dvec.end())
	{
		it = it2->begin();
		while (it != it2->end())
		{
			vec.push_back(*it);
			it++;
		}
		it2++;
	}
	print();
	createMainChain();
	createPendChain();
}

void	PmergeMe::insertion(dvector::iterator it)
{

	createPair();
	if (dvec.size() > 3 && (it->size() == (it + 1)->size()))
			insertion(it);
}


// __ Create Main Chain ________________________________________________________
// =============================================================================
void	PmergeMe::createMainChain()
{
	vector::iterator	it;
	vector		tmp;
	int	i;

	it = vec.begin();
	i = 0;
	while (it != vec.end())
	{
		if (i == 0 || i % 2 == 1)
		{
			tmp.push_back(*it);
			mainChain.push_back(tmp);
			tmp.clear();
		}
		it++;
		i++;
	}
	// print
	printVector(mainChain);
}

// __ Create Pend Chain ________________________________________________________
// =============================================================================
void	PmergeMe::createPendChain()
{
	vector::iterator	it;
	vector		tmp;
	int		i;

	i = 0;
	it = vec.begin();
	while (it != vec.end())
	{
		if (i > 0 && i % 2 == 0)
		{
			tmp.push_back(*it);
			pendChain.push_back(make_pair(tmp, ++it));
			tmp.clear();
			i++;
		}
		if (it == vec.end())
			break;
		it++;
		i++;
	}
	// print
	pair_vector::iterator it2;
	it2 = pendChain.begin();
	while (it2 != pendChain.end())
	{
		it = it2->second;
		std::cout << *(it2->first.begin()) << " " << *(it) << "|";
		it2++;
	}
	std::cout << std::endl;

}

// __ create Pair ______________________________________________________________
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
	// print
	printVector(dvec);
}

// __ Print Vector of Vector ___________________________________________________
// =============================================================================
void	PmergeMe::printVector(dvector cont)
{
	vector::iterator it;
	dvector::iterator dit;

	std::cout << "====== Vector 2 ===========" << std::endl;
	dit = cont.begin();
	while (dit != cont.end())
	{
		std::cout << "|";
		it = dit->begin();		
		while (it != dit->end())
		{
			std::cout << " " << *it << " ";
			it++;
		}
		dit++;
	}
	std::cout << std::endl;
}

// __ Print Vector _____________________________________________________________
// =============================================================================
void	PmergeMe::print()
{
	vector::iterator it;

	std::cout << "====== Vector 1 ===========" << std::endl;
	it = vec.begin();		
	while (it != vec.end())
	{
		std::cout << *it << std::endl;
		it++;
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

