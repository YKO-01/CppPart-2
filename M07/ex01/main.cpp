/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:58:51 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/01 23:55:36 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void function(const char arr)
{
	std::cout << arr << std::endl;
}



int main()
{
	int size = 10;
	const char arr[10] = {'A', 'B', '6', 2, 0, 4, 5, 9, 8, 7};

	::iter(arr, size, function);
	return (0);
}
