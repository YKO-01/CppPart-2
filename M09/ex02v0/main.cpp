/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:11:03 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/24 09:48:10 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParsingArg.hpp"
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac <= 2)
		return (0);
	try
	{
		ParsingArg parg;
		parg.validArgument(&av[1]);
		PmergeMe pm(&av[1]);
		pm.sortNumbers();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
