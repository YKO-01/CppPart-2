/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:11:57 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/24 10:05:04 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include "MyException.hpp"
#include <utility>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>

//extern int	comparasion;
#include "SVector.hpp"
#include "List.hpp"

class PmergeMe
{
	private:
		SVector	sortVec;
		List	sortLst;
	public:
		PmergeMe();
		PmergeMe(char **arg);
		PmergeMe(const PmergeMe& copy);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& copy);
		void	sortNumbers();
};

#endif
