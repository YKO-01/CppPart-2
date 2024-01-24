/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:53:28 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/24 11:28:03 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <list>
#include <algorithm>
#include <chrono>
#include <ctime>

//extern int	comparasion;

typedef	std::list<int>	list;
typedef std::list<list>	dlist;
typedef std::list<std::pair<dlist, dlist::iterator> >	pair_list;

class List
{
	private:
		list	_list;
		dlist	_dlist;
		dlist	mainChain;
		pair_list	pendChain;
	public:
		List();
		List(char **arg);
		List(const List& copy);
		~List();
		List&	operator=(const List& copy);
		void	sortlist();
		void	fillDlist(std::list<int>::iterator it);
		void	createPair(dlist& dvect);
		void	insertionList();
		void	createMainChainList();
		void	createPendChainList();
		int		getCountPairList();
		void	splitPair(dlist fvect);
		void	insertPendToMainList();
		void	sortPairList();
		void	reverseSort(dlist tmp, int *var);
		void	printList();
		void	stockRest(dlist&tmp, int& var);
		dlist::iterator advanceIterator(dlist& doubleList, dlist::iterator it, int index);
		list::iterator	miniAdvance(list& lst, list::iterator it, int index);
};

#endif
