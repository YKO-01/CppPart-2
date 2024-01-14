/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:11:57 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/14 16:08:54 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include "MyException.hpp"
#include <utility>
#include <vector>
#include <algorithm>


typedef	std::vector<int>	vector;
typedef std::vector<vector>	dvector;
typedef std::vector<std::pair<dvector, dvector::iterator> >	pair_vector;

class PmergeMe
{
	private:
		vector	vec;
		dvector	dvec;
		dvector	mainChain;
		pair_vector	pendChain;
	public:
		PmergeMe();
		PmergeMe(char **arg);
		PmergeMe(const PmergeMe& copy);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& copy);
		void	initVectors();
		void	fillDVector(std::vector<int>::iterator it);
		void	createPair();
		void	printVector(dvector);
		void	insertion();
		void	createMainChain();
		void	createPendChain();
		int		getCountPair();
		void	splitPair();
		void	insertPendToMain();
		void	print();
};

#endif
