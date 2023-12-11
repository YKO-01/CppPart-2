/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:46:08 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/11 17:01:43 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack();
		MutantStack(const MutantStack& copy);
		~MutantStack();
		MutantStack& operator = (const MutantStack& copy);
		typedef typename std::stack<T>::container_type::iterator		iterator;
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"	


#endif
