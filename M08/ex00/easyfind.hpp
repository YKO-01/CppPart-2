/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:14:32 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/06 13:06:20 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

template <typename T>
T	easyfind(std::vector<T>first, int second)
{
	int i;
	i = -1;
	while (++i < (int)first.size())
	{
		if (first.at(i) == second)
			return (i);
	}
	throw "element not found";

}



#endif
