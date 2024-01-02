/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:32:39 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/01 23:53:08 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <class T1, class T2>

void	iter(T1 &ptr, int size, void (*fun)(T2))
{
	int i = -1;
	while (++i < size)
	{
		fun(ptr[i]);
	}
}

#endif
