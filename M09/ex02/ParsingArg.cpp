/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParsingArg.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:18:21 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/24 11:07:46 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParsingArg.hpp"

// __ Constructure Destructure _________________________________________________
// =============================================================================
ParsingArg::ParsingArg()
{
}

ParsingArg::~ParsingArg()
{
}

int	ParsingArg::isoperator(char c)
{
	char op[4] = {'+', '-', '/', '*'};
	int i;

	i = -1;
	while (++i < 4)
		if (c == op[i])
			return (1);
	return (0);
}

// __ validArgument() __________________________________________________________
// =============================================================================
void	ParsingArg::validArgument(char **arg)
{
	scanArgument(arg);
}

// __ scanArgument() ___________________________________________________________
// =============================================================================
void	ParsingArg::scanArgument(char **arg)
{
	int	i;
	int	j;
	
	i =-1;
	while (arg[++i])
	{
		j = -1;
		if (arg[i][0] == '+' || arg[i][0] == '-')
			j = 0;
		while (arg[i][++j])
			if (!std::isdigit(arg[i][j]))
				throw MyException("Error");
	}

}

