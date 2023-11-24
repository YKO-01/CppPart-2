/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:53:57 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/24 11:38:34 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

// __ Swap Function ____________________________________________________________
// =============================================================================
template <class T>
void	swap(T &first, T &second)
{
	T tmp;

	tmp = first;
	first = second;
	second = tmp;
}

// __ Min Function _____________________________________________________________
// =============================================================================
template <class T>
T	min(T first, T second)
{
	return (first < second ? first : second);
}

// __ Max Function _____________________________________________________________
// =============================================================================
template <class T>
T	max(T first, T second)
{
	return (first > second ? first : second);
}

#endif
