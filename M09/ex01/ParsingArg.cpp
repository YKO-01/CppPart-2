/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParsingArg.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:18:21 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/02/22 17:02:57 by ayakoubi         ###   ########.fr       */
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
void	ParsingArg::validArgument(std::string arg)
{
	scanArgument(arg);
	checkMatters(arg);
	validOperation(arg);
}

// __ scanArgument() ___________________________________________________________
// =============================================================================
void	ParsingArg::scanArgument(std::string arg)
{
	size_t	i;
	size_t	size;
	int		j;

	size = arg.length();
	i = -1;
	while (++i < size)
	{
		j = -1;
		if (!std::isdigit(arg[i]) && arg[i] != ' ')
		{
			if (isoperator(arg[i]) && isoperator(arg[i + 1]))
					throw MyException("Error");
			if (isoperator(arg[i]) && isdigit(arg[i + 1]))
					throw MyException("Error");
		}
	}	

}

// __ checkMatters() ___________________________________________________________
// =============================================================================
void	ParsingArg::checkMatters(std::string arg)
{
	size_t	i;
	size_t	start;
	size_t	size;
	std::string str;

	size = arg.length();
	i = -1;
	start = 0;
	while (++i < size)
	{
		if (arg[i] == ' ')
		{
			if (arg[i + 1] == ' ' || isoperator(arg[i + 1]))
				continue;
			str = arg.substr(start, i - 1);
			if (std::atoi(str.c_str()) < 0 || std::atoi(str.c_str()) > 9)
				throw MyException("error");
			start = i + 1;
		}
	}
}

// __ validOperation() _________________________________________________________
// =============================================================================
void	ParsingArg::validOperation(std::string arg)
{
	size_t	i;
	int count;
	int oper;

	i  = -1;
	count = 0;
	oper = 0;
	while (++i < arg.length())
	{
		if (isdigit(arg[i]))
			count++;
		else if (isoperator(arg[i]))
			oper++;
	}
	if (count != oper + 1)
		throw MyException("Error");
}
