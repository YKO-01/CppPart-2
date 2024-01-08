/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParsingArg.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:18:21 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/05 18:43:50 by ayakoubi         ###   ########.fr       */
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
//	checkMatters(arg);
//	validOperation(arg);
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
/*
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
		if (isdigit(arg[i]))
			arr.push_back(std::atoi(&arg[i]));
		else if (isoperator(arg[i]))
			arr.push_back(isoperator(arg[i]));
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
}*/
