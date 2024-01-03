/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:58:51 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/02 02:57:38 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printArr(const char arr)
{
	std::cout << arr << std::endl;
}

int main()
{
	int size = 10;
	const char arr[10] = {'A', 'B', '6', '2', '0', 49, 65, 96, 88, 77};

	::iter(arr, size, printArr);
	return (0);
}
