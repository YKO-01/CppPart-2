/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SVector.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:57:38 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/24 11:27:36 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	VECTOR_HPP
#define	VECTOR_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>

//extern int	comparasion;

typedef	std::vector<int>	vector;
typedef std::vector<vector>	dvector;
typedef std::vector<std::pair<dvector, dvector::iterator> >	pair_vector;

class SVector
{
	private:
		vector	vec;
		dvector	dvec;
		dvector	mainChain;
		pair_vector	pendChain;
	public:
		SVector();
		SVector(char **arg);
		SVector(const SVector& copy);
		~SVector();
		SVector&	operator=(const SVector& copy);
		void	sortVector();
		void	fillDVector(std::vector<int>::iterator it);
		void	createPair(dvector& dvect);
		void	insertion();
		void	createMainChain();
		void	createPendChain();
		int		getCountPair();
		void	splitPair(dvector fvect);
		void	insertPendToMain();
		void	updateIterator(dvector::iterator it);
		void	sortPair();
		void	print();
		void	stockRest(dvector&tmp, int& var);	
};

#endif
