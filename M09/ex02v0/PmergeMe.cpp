/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:42:39 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/18 11:44:02 by ayakoubi         ###   ########.fr       */
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

	it = vec.begin();
	insertion();
	printVector(dvec);
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

	dvector tmp;
	vector	_tmp;
	int var = 0;
	while (1)
	{
			createPair(dvec);
			sortPair();
			if (getCountPair() <= 2)
				break;
	}	
	while (1)
	{
		splitPair(mainChain);
		if ((dvec.end() - 1)->size() != dvec.begin()->size())
		{
			tmp = dvec;
			dvec.pop_back();
			var = 1;
		}
		else if(tmp.size() && (dvec.begin())->size() <= (tmp.end() - 1)->size() && var == 1)
		{
			dvec.push_back(*(tmp.end() - 1));
			var = 0;
			if ((dvec.end() - 1)->size() > dvec.begin()->size())
			{
				tmp.clear();
				_tmp.push_back(*((dvec.end() - 1)->end() - 1));
				tmp.push_back(_tmp);
				(dvec.end() - 1)->pop_back();
				var = 1;
			}
		}
		mainChain.clear();
		createMainChain();
		pendChain.clear();
		createPendChain();
		insertPendToMain();
		dvec = mainChain;
		if (mainChain.begin()->size() == 1)
			return;
	}
}

void	PmergeMe::reverseSort(dvector tmp, int *var)
{
	dvec = tmp;
	splitPair(mainChain);
	if ((dvec.end() - 1)->size() != dvec.begin()->size())
	{
		tmp.clear();
		tmp.push_back(*(dvec.end()));
		dvec.pop_back();
		*var = 1;
	}
	else if((dvec.end() - 1)->size() == tmp.begin()->size() && *var == 1)
		dvec.push_back(*(tmp.begin()));
	std::cout << "\n=========== Vector of Vector =========" << std::endl; 
	printVector(dvec);
	std::cout << "\n======= Main Chain =========" << std::endl;
	mainChain.clear();
	createMainChain();
	std::cout << "\n======= Pend Chain =========" << std::endl;
	pendChain.clear();
	createPendChain();
	insertPendToMain();
	std::cout << "\n======= New Main Chain =========" << std::endl;
	printVector(mainChain);
}


int	comp(const vector& main_chain, const vector& value)
{
	return (main_chain.back() < value.back());
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
		pos = std::lower_bound(mainChain.begin(), mainChain.end(), it->first.front(), comp);
		mainChain.insert(pos, *(it->first.begin()));
		if (it == pendChain.end())
			break;
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
}

// __ create Pair ______________________________________________________________
// =============================================================================
void	PmergeMe::createPair(dvector& dvect)
{
	vector::iterator it;
	dvector::iterator dit;
	dvector::iterator tmp;
	
	it = vec.begin();
	if (!dvect.size())
	{
		fillDVector(it);
		return;
	}
	dit = dvect.begin();
	while (dit != dvect.end())
	{
		it = dit->begin();
		if (dit != dvect.end() - 1)
		{
			tmp = dit + 1;
			dit->insert(dit->end(), tmp->begin(), tmp->end());
			tmp->erase(tmp->begin(), tmp->end());
			dvect.erase(tmp);
		}
		dit++;
	}
}

// __ Split Pair _______________________________________________________________
// =============================================================================
void	PmergeMe::splitPair(dvector dvect)
{
	dvector::iterator	dit;
	vector				tmp;
	vector::iterator	it;
	size_t				i;
	int var;

	dit = dvect.begin();
	if (dvect.size() != 0)
		dvec.clear();
	else
		return ;
	
	while (dit != dvect.end())
	{
		i = -1;
		var = 1;
		it = dit->begin();
		if (!(dit->size() % 2))
			var = 0;
		while (++i < (dit->size() / 2) + var)
		{
			tmp.push_back(*it);
			it++;
		}
		dvec.push_back(tmp);
		tmp.clear();
		while (it != dit->end())
		{
			tmp.push_back(*it);
			it++;
		}
		dvec.push_back(tmp);
		tmp.clear();
		dit++;
	}
}

// __ Sort Pair _______________________________________________________________
// ============================================================================
void	PmergeMe::sortPair()
{
	dvector::iterator dit;
	dvector::iterator tmp;
	
	dit = dvec.begin();
	while (dit != dvec.end())
	{
		if (dit != dvec.end() - 1)
		{
			tmp = dit + 1;
			if (dit->back() > tmp->back())
				dit->swap(*(tmp));
			dit++;
		}
		if (dit == dvec.end())
			break;
		dit++;
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

//	std::cout << "====== Vector 2 ===========" << std::endl;
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

