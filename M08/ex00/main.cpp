/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:28:30 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/06 13:12:02 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


int main(void)
{
	std::vector<int> nums;
   	nums.push_back(10);
	nums.push_back(23);
	nums.push_back(64);
	nums.push_back(22);
	try
	{
		int find = easyfind(nums, 50);
		std::cout << find << std::endl;
	}
	catch(const char* str)
	{
		std::cout << str << std::endl;
	}
	return (0);
}
