/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:32:39 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/25 12:35:58 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <class T>
void function(T first)
{
	std::cout << first << std::endl;
}


template <class T1, class T2, class T3>

void	iter(T1 &ptr, T2 size, void (*fun)(T3))
{
	int i = -1;
	while (++i < size)
	{
		fun(ptr[i]);
	}
}

#endif
