/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:42:39 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/20 14:52:54 by ayakoubi         ###   ########.fr       */
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
		std::cout << "\n======= Main Chain =========" << std::endl;
		mainChain.clear();
		createMainChain();
		printVector(mainChain);
		std::cout << "\n======= Pend Chain =========" << std::endl;
		pendChain.clear();
		createPendChain();
	//	printVector(pendChain);
		insertPendToMain();
		std::cout << "\n======= New Main Chain =========" << std::endl;
		printVector(mainChain);
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
	return (main_chain.back() <= value.back());
}


// __ Insert Pend to Main ______________________________________________________
// =============================================================================
void	PmergeMe::insertPendToMain()
{
	dvector::iterator	pos;
	pair_vector::iterator it;
	static std::uint_least64_t jacobsthal_diff[] = {
        2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
        2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
        1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
        178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
        11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
        366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
        11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
        375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
        6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
        96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
        1537228672809129216u, 3074457345618258432u, 6148914691236516864u
    };

	it = pendChain.begin();
	int i;
	uint_least64_t dist;
	i = 0;
	while (pendChain.size())
	{
		it = pendChain.begin();
		dist = jacobsthal_diff[i];
		if (dist >= pendChain.size())
			it = pendChain.end() - 1;
		else
			std::advance(it, dist);
		while (1)
		{
			pos = std::lower_bound(mainChain.begin(), mainChain.end(), it->first.front(), comp);
			mainChain.insert(pos, *(it->first.begin()));
			it = pendChain.erase(it);
		//	updateIterator(it, i);
			if (it == pendChain.begin())
				break;
			--it;
		}
		i++;
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
			if (dit->back() >= tmp->back())
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

