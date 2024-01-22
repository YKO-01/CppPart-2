/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:11:03 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/22 11:10:41 by ayakoubi         ###   ########.fr       */
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
		pm.sortVector();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
