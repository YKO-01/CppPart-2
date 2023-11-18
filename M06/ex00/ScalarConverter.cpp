/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:06:33 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/18 10:06:34 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <sstream>
#include <iomanip>

// __ Constructo & Destructor _______________________________________________________________________
// ==================================================================================================
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

// __ Check Conver __________________________________________________________________________________
// ==================================================================================================
bool	checkConvert(std::string arg)
{
	int i = -1;
	int k = 0;
	int len = (int)arg.length() - 1;
	if (len >= 1)
	{
		if (arg[0] == '-')
			i++;
		while (++i <= len)
		{
			if (i == len && arg[i] == 'f')
				return (true);
			if (arg[i] != '.' && (arg[i] < '0' || arg[i] > '9'))
				return (false);
			if (arg[i] == '.')
				k++;
		}
		if (k > 1)
			return (false);
	}
	return (true);
}

// __ Get Type  _____________________________________________________________________________________
// ==================================================================================================
std::string getType(std::string arg)
{
	int len = (int)arg.length() - 1;
	if (len == 0 && (arg[0] < '0' || arg[0] > '9'))
		return ("char");
	if (arg[len] == 'f')
		return ("float");
	if (find(arg.begin(), arg.end(), '.') != arg.end())
		return ("double");
	return ("int");
}

// __ Display Impossible ____________________________________________________________________________
// ==================================================================================================
void	displayImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

// __ Cast From Char ________________________________________________________________________________
// ==================================================================================================
void	fromChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

// __ Cast From Int _________________________________________________________________________________
// ==================================================================================================
void	fromInt(std::string arg)
{
	std::istringstream varInt(arg);
	int nbr;
	if (!(varInt >> nbr))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (nbr < 38 || nbr > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
		std::cout << "int: " << nbr << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(nbr) << std::endl;

}
// __ Cast From Float _______________________________________________________________________________
// ==================================================================================================
		
void	fromFloat(std::string arg)
{
	std::istringstream varFloat(arg);
	float nbr;
	varFloat >> nbr;
	if (nbr < 38 || nbr > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	if (nbr < INT_MIN || nbr > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << nbr << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(nbr) << std::endl;

}
// __ Cast From Double ______________________________________________________________________________
// ==================================================================================================

void	fromDouble(std::string arg)
{
	std::istringstream varFloat(arg);
	double nbr;
	varFloat >> nbr;
	if (nbr < 38 || nbr > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
	if (nbr < INT_MIN || nbr > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double: " << nbr << std::endl;

}
// __ ScalarConverter Convert _______________________________________________________________________
// ==================================================================================================

void ScalarConverter::convert(std::string argument)
{
	std::string type;
	if (checkConvert(argument) == false)
		displayImpossible();
	else
	{
		type = getType(argument);
		std::cout << type << std::endl;
		if (type == "char")
			fromChar(argument[0]);
		if (type == "int")
			fromInt(argument);
		if (type == "float")
		{
			argument.erase(argument.length() - 1);
			fromFloat(argument);
		}
		if (type == "double")
			fromDouble(argument);
	}	
}
