/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:09:21 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/23 12:30:06 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

template <class T>
Whatever<T>::Whatever()
{
}

template <class T>
void	Whatever<T>::swap(T first, T second)
{
	T tmp;

	tmp = first;
	first = second;
	second = tmp;
}

