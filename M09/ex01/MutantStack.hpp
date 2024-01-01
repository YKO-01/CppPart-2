/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:46:08 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/14 10:36:06 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <type_traits>
#include <memory>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack();
		MutantStack(const MutantStack& copy);
		~MutantStack();
		MutantStack& operator = (const MutantStack& copy);
		typedef std::allocator_traits<__pointer_allocator> traits;
		class iterator
		{
			private :
				traits::pointer ptr;
		}
		typedef typename std::stack<T>::container_type::iterator		iterator;
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"	


#endif
