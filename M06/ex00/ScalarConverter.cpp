/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:06:33 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/29 13:27:36 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <sstream>
#include <iomanip>
#include <climits>

// __ Constructo & Destructor __________________________________________________
// =============================================================================
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

// __ Check Conver _____________________________________________________________
// =============================================================================
bool	checkConvert(std::string arg)
{
	int i = -1;
	int k = 0;
	int len = (int)arg.length() - 1;
	int ret = 0;

	if (len == 0)
		return (true);
	if (arg[0] == '-')
		i++;
	while (++i <= len)
	{
		if (arg[i] != ' ')
			ret = 1;
		if (i < len && ret == 1 && arg[i] == ' ' && arg[i + 1] != ' ')
			return (false);
		if (i == len && arg[i] == 'f')
			return (true);
		if (arg[i] != ' ' && arg[i] != '.' && !isdigit(arg[i]))
			return (false);
		if (arg[i] == '.')
			k++;
	}
	if (k > 1)
		return (false);
	return (true);
}

// __ Get Type  ________________________________________________________________
// =============================================================================
std::string getType(std::string arg)
{
	int len = (int)arg.length() - 1;
	if (len == 0 && (arg[0] < '0' || arg[0] > '9'))
		return ("char");
	if (arg[len] == 'f')
		return ("float");
	if (arg.find(0, len, '.') < len)
		return ("double");
	return ("int");
}

// __ Display Impossible _______________________________________________________
// =============================================================================
void	displayImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

// __ Cast From Char ___________________________________________________________
// =============================================================================
void	fromChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

// __ Cast From Int ____________________________________________________________
// =============================================================================
void	fromInt(std::string arg)
{
	std::istringstream varInt(arg);
	int nbr;
	if (!(varInt >> nbr))
		displayImpossible();
	else
	{
		if (nbr < 38 || nbr > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
		std::cout << "int: " << nbr << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nbr) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(nbr) << std::endl;
	}

}
// __ Cast From Float __________________________________________________________
// =============================================================================
		
void	fromFloat(std::string arg)
{
	std::istringstream varFloat(arg);
	float nbr;
	if (!(varFloat >> nbr))
		displayImpossible();
	else
	{
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

}
// __ Cast From Double _________________________________________________________
// =============================================================================

void	fromDouble(std::string arg)
{
	std::istringstream varDouble(arg);
	double nbr;
	if (!(varDouble >> nbr))
		displayImpossible();
	else
	{
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

}
// __ ScalarConverter Convert __________________________________________________
// =============================================================================

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
