/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:56:27 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/02/20 10:38:52 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"

// __ Constructurs _____________________________________________________________
// =============================================================================
List::List()
{
}

List::List(char **arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		_list.push_back(std::atoi(arg[i]));
}

// __ Copy Constructure ________________________________________________________
// =============================================================================
List::List(const List& copy)
{
	*this = copy;
}

// __ Destructure ______________________________________________________________
// =============================================================================
List::~List()
{
}

// __ Asignement Operator ______________________________________________________
// =============================================================================
List& List::operator = (const List& copy)
{
	this->_list = copy._list;
	this->_dlist = copy._dlist;
	this->mainChain = copy.mainChain;
	return (*this);
}

// __ Asignement Op_erator ______________________________________________________
// =============================================================================
void	List::sortlist()
{
	dlist::iterator dit;
	clock_t start = clock();	
	insertionList();
	clock_t end = clock();
	double duration = static_cast<double>(end - start) * 1e6 / CLOCKS_PER_SEC;
	dit = _dlist.begin();	
	while (dit != _dlist.end())
	{
		_list.push_back(*(dit->begin()));
		dit++;
	}
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list : " << duration << " us" << std::endl;
}


int 	List::getCountPairList()
{
	dlist::iterator it;
	dlist::iterator tmp;
	int	count;

	count = 0;
	it = _dlist.begin();
	while (it != _dlist.end())
	{
		tmp = advanceIterator(_dlist, it, 1);
		if (it->size() == tmp->size())
			count++;
		it++;
	}
	return (count);
}

// __ insertion ________________________________________________________________
// =============================================================================
void	List::insertionList()
{
	dlist tmp;
	int var = 0;
	while (1)
	{
			createPair(_dlist);
			sortPairList();
			if (getCountPairList() <= 2)
				break;
	}
	while (1)
	{
		splitPair(mainChain);
		stockRest(tmp, var);
		mainChain.clear();
		createMainChainList();
		pendChain.clear();
		createPendChainList();
		insertPendToMainList();
		_dlist = mainChain;
		if (mainChain.begin()->size()  == 1)
			return;
	}
}

// __ Stock Rest _______________________________________________________________
// =============================================================================
void	List::stockRest(dlist& tmp, int& var)
{
	list	_tmp;
	dlist::iterator _end;
	dlist::iterator _begin;
	list::iterator	it;

	_begin = _dlist.begin();
	_end = advanceIterator(_dlist, _dlist.end(), -1);
	if (_end->size() != _begin->size())
	{
		tmp.push_back(*_end);
		_dlist.pop_back();
		var = 1;
	}
	else if(tmp.size() && _begin->size() <= tmp.begin()->size() && var == 1)
	{
		_dlist.push_back(*(advanceIterator(tmp, tmp.end(), - 1)));
		var = 0;
		_begin = _dlist.begin();
		_end = advanceIterator(_dlist, _dlist.end() , -1);
		if (_end->size() > _begin->size())
		{
			tmp.clear();
			for (size_t i = _begin->size(); i < _end->size(); i++)
			{
				it = _end->begin();
				it = miniAdvance(*_end, it, i);
				_tmp.push_back(*it);
			}
			tmp.push_back(_tmp);
			for (size_t i = _end->size(); i > _begin->size(); --i)
				_end->pop_back();
			var = 1;
		}
	}
}

// __ compare  _____________________________________________________________
// =============================================================================
int	comp(const list& main_chain, const list& value)
{
	return (main_chain.back() <= value.back());
}

// __ Insert Pend to Main ______________________________________________________
// =============================================================================
void	List::insertPendToMainList()
{
	dlist::iterator	pos;
	pair_list::iterator it;
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

	int i;
	uint_least64_t dist;
	i = 0;
	while (pendChain.size())
	{
		it = pendChain.begin();
		dist = jacobsthal_diff[i];
		uint_least64_t j = 0; 
		while (j < dist && it != pendChain.end())
		{
			j++;
			it++;
		}
		if (it == pendChain.end())
			it--;
		while (1)
		{
			pos = std::lower_bound(mainChain.begin(), it->second, it->first.front(), comp);
			mainChain.insert(pos, *(it->first.begin()));
			pendChain.erase(it);
			--it;
			if (it == pendChain.begin())
				break;
		}
		i++;
	}

}

// __ Create Main Chain ________________________________________________________
// =============================================================================
void	List::createMainChainList()
{
	dlist::iterator	it;
	int	i;

	it = _dlist.begin();
	i = 0;
	while (it != _dlist.end())
	{
		if (i == 0 || i % 2 == 1)
			mainChain.push_back(*it);
		it++;
		i++;
	}
}

// __ Create Pend Chain ________________________________________________________
// =============================================================================
void	List::createPendChainList()
{
	dlist::iterator	dit;
	dlist::iterator	mit;
	pair_list::iterator	pit;
	dlist::iterator		_end;
	dlist					tmp;
	int i;

	i = 0;
	dit = _dlist.begin();
	pit = pendChain.begin();
	mit = advanceIterator(mainChain, mainChain.begin(), 1);
	_end = advanceIterator(_dlist, _dlist.end(), -1);
	while (dit != _dlist.end())
	{
		if ((i > 0 && i % 2 == 0) || (dit != _end && dit->size() != _dlist.begin()->size()))
		{
			tmp.push_back(*dit);
			pendChain.push_back(make_pair(tmp, ++mit));	
			tmp.clear();
			dit++;
			i++;	
		}
		if (dit == _dlist.end())
			break;
		dit++;
		i++;
	}
}

// __ create Pair ______________________________________________________________
// =============================================================================
void	List::createPair(dlist& dlistt)
{
	list::iterator it;
	dlist::iterator dit;
	dlist::iterator tmp;
	dlist::iterator	_end;
	
	it = _list.begin();
	if (!dlistt.size())
	{
		fillDlist(it);
		return;
	}
	dit = dlistt.begin();
	while (dit != dlistt.end())
	{
		it = dit->begin();
		_end = advanceIterator(dlistt, dlistt.end(), -1);
		if (dit != _end)
		{
			tmp = advanceIterator(dlistt, dit, 1);
			dit->insert(dit->end(), tmp->begin(), tmp->end());
			tmp->erase(tmp->begin(), tmp->end());
			dlistt.erase(tmp);
		}
		dit++;
	}
}

// __ Fill Dlist _______________________________________________________________
// =============================================================================
void	List::fillDlist(std::list<int>::iterator it)
{
	list tmp;
	list::iterator _end;
	tmp.push_back(*it);
	_dlist.push_back(tmp);
	_end = _list.end();
	_end--;
	if (it != _end)
		fillDlist(++it);
	_list.pop_back();
}

// __ Split Pair _______________________________________________________________
// =============================================================================
void	List::splitPair(dlist dlistt)
{
	dlist::iterator	dit;
	list				tmp;
	list::iterator	it;
	size_t				i;
	int var;

	dit = dlistt.begin();
	if (dlistt.size() != 0)
		_dlist.clear();
	else
		return ;
	
	while (dit != dlistt.end())
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
		_dlist.push_back(tmp);
		tmp.clear();
		while (it != dit->end())
		{
			tmp.push_back(*it);
			it++;
		}
		_dlist.push_back(tmp);
		tmp.clear();
		dit++;
	}
}

// __ Sort Pair _______________________________________________________________
// ============================================================================
void	List::sortPairList()
{
	dlist::iterator dit;
	dlist::iterator tmp;
	
	dit = _dlist.begin();
	while (dit != _dlist.end())
	{ 
		if (dit != advanceIterator(_dlist, _dlist.end(), -1))
		{
			tmp = advanceIterator(_dlist, dit, 1);
			if (dit->size() == tmp->size() && dit->back() >= tmp->back())
				dit->swap(*(tmp));
			dit++;
		}
		if (dit == _dlist.end())
			break;
		dit++;
	}
}

// __ Print list _____________________________________________________________
// =============================================================================
void	List::printList()
{
	list::iterator it;

	it = _list.begin();		
	while (it != _list.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
	
// __ Advance Iterator _________________________________________________________
// =============================================================================
dlist::iterator	List::advanceIterator(dlist& doubleList, dlist::iterator it, int index)
{
	dlist::iterator newit;
	dlist::iterator _begin;
	_begin = doubleList.begin();
	newit = it;
	int i;
	int len;
	i = -1;
	if (index < 0)
	{
		i = 0;
		while (_begin != it)
		{
			_begin++;
			i++;
		}
		len = i - index * -1;
		while(newit != doubleList.begin() && i-- > len)
			newit--;
		return (newit);
	}
	while (newit != doubleList.end() && ++i < index)
		newit++;
	return (newit);
}

// __ mini Advance _____________________________________________________________
// =============================================================================
list::iterator	List::miniAdvance(list& lst, list::iterator it, int index)
{
	list::iterator newit;
	int i;

	newit = it;
	i = -1;
	while (newit != lst.end() && ++i < index)
		newit++;
	return (newit);
}
