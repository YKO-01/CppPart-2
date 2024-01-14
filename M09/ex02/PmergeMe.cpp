/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:42:39 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/14 16:22:58 by ayakoubi         ###   ########.fr       */
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

	fillDVector(it);
	it = vec.begin();
	printVector(dvec);
	insertion();
	std::cout << "\n======= Main Chain =========";
	mainChain.clear();
	createMainChain();
	std::cout << "\n======= Pend Chain =========" << std::endl;
	pendChain.clear();
	createPendChain();
}


int 	PmergeMe::getCountPair()
{
	dvector::iterator it;
	int	count;

	count = 0;
	it = dvec.begin();
	while (it != dvec.end())
	{
		if (it->size() == (it + 1)->size())
			count++;
		it++;
	}
	return (count);
}

void	PmergeMe::insertion()
{

	createPair();
	if (getCountPair() > 2)
		insertion();
	std::cout << "\n======= Main Chain =========";
	mainChain.clear();
	createMainChain();
	std::cout << "\n======= Pend Chain =========" << std::endl;
	pendChain.clear();
	createPendChain();
//	insertPendToMain();
//	printVector(mainChain);
	dvec.clear();
	splitPair();
	//printVector(dvec);
}

// __ Insert Pend to Main ______________________________________________________
// =============================================================================
void	PmergeMe::insertPendToMain()
{
	dvector::iterator	pos;
	pair_vector::iterator it;

	it = pendChain.begin();
	while (it != pendChain.end())
	{
		pos = std::lower_bound(mainChain.begin(), mainChain.end(), *(it->first.begin()));
		mainChain.insert(pos, mainChain.begin(), mainChain.end());
		mainChain.erase(pos);
		it++;
	}

}
// __ Create Main Chain ________________________________________________________
// =============================================================================
void	PmergeMe::createMainChain()
{
	dvector::iterator	it;
	int	i;

	it = dvec.begin();
	i = 0;
	while (it != dvec.end())
	{
		if (i == 0 || i % 2 == 1)
			mainChain.push_back(*it);
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
	dvector::iterator	dit;
	pair_vector::iterator	pit;
	dvector					tmp;
	int i;

	i = 0;
	dit = dvec.begin();
	pit = pendChain.begin();
	while (dit != dvec.end())
	{
		if ((i > 0 && i % 2 == 0) || (dit != dvec.end() - 1 && dit->size() != dvec.begin()->size()))
		{
			tmp.push_back(*dit);
			pendChain.push_back(make_pair(tmp, ++dit));
			tmp.clear();
			//pit++;
			i++;
		}
		if (dit == dvec.end())
			break;
		dit++;
		i++;
	}
	// print
	pair_vector::iterator it2;
	it2 = pendChain.begin();
	vector::iterator it;
	while (it2 != pendChain.end())
	{
		std::cout << "|(";
		dit = it2->first.begin();
		while (dit != it2->first.end())
		{
			it = dit->begin();
			while (it != dit->end())
			{
				std::cout << *(it) << " ";
				it++;
			}
			dit++;
		}
		std::cout << ", " << *(it2->second->begin()) << ")";
		it2++;
	}
	std::cout << "|" << std::endl;

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

// __ Split Pair _______________________________________________________________
// =============================================================================
void	PmergeMe::splitPair()
{
	dvector::iterator	mit;
	vector				tmp;
	vector::iterator	it;
	size_t				i;
	int var;

	mit = mainChain.begin();
	while (mit != mainChain.end())
	{
		i = -1;
		var = 1;
		it = mit->begin();
		if (!(mit->size() % 2))
			var = 0;
		while (++i < (mit->size() / 2) + var)
		{
			tmp.push_back(*it);
			it++;
		}
		dvec.push_back(tmp);
		tmp.clear();
		while (it != mit->end())
		{
			tmp.push_back(*it);
			it++;
		}
		dvec.push_back(tmp);
		tmp.clear();
		mit++;
	}
}



/*
// __ Copy Main Choin __________________________________________________________
// =============================================================================
void	PmergeMe::copyMainChain()
{
	dvector::iterator it;

	it = mainCain.begin();
*/
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
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
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

