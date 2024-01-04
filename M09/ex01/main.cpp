/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:54:45 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/04 17:29:31 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParsingArg.hpp"
#include "RPN.hpp"

int main(int ac, char **av)
{
	ParsingArg	pArg;
	RPN	rpn;
	int ret;


	if (ac != 2)
		return (1);
	try
	{
		pArg.validArgument(av[1]);
		rpn.calculate(av[1], &ret);
		std::cout << ret << std::endl;

	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

