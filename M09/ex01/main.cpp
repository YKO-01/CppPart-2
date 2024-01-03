/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:54:45 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/03 00:01:21 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParsingArg.hpp"
#include "RPN.hpp"

int main(int ac, char **av)
{
	ParsingArg	pArg;
	RPN	rpn;


	if (ac != 2)
		return (1);
	try
	{
		pArg.validArgument(av[1]);

	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

