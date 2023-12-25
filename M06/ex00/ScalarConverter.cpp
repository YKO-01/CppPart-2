/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:06:33 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/25 09:05:20 by ayakoubi         ###   ########.fr       */
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

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
}

// __ Assignement Operator _____________________________________________________
// =============================================================================
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void) copy;
	return (*this);
}

// __ Check Conver _____________________________________________________________
// =============================================================================
bool	ScalarConverter::checkConvert(std::string arg)
{
	int i = -1;
	int k = 0;
	int len = static_cast<int>(arg.length() - 1);
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
		if (arg[len] == 'f' && arg[len - 1] == '.')
			return (true);
		if (arg[len] == 'f' && arg[len - 1] != '.')
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
e_type ScalarConverter::getType(std::string arg)
{
	size_t len = arg.length() - 1;

	if (arg == "-inf" || arg == "+inf" || arg == "nan")
		return (PSEUDODOUBLE);
	if (arg == "-inff" || arg == "+inff" || arg == "nanf")
		return (PSEUDOFLOAT);
	if (checkConvert(arg) == false)
		return (STRING);
	if (len == 0 && (arg[0] < '0' || arg[0] > '9'))
		return (CHAR);
	if (arg[len] == 'f')
		return (FLOAT);
	if (arg.find(".") < len)
		return (DOUBLE);
	return (INT);
}

// __ Display Impossible _______________________________________________________
// =============================================================================
void	ScalarConverter::displayImpossible(std::string arg)
{
	(void) arg;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

// __ Cast From Char ___________________________________________________________
// =============================================================================
void	ScalarConverter::fromChar(std::string arg)
{
	char c;

	c = arg[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

// __ Cast From Int ____________________________________________________________
// =============================================================================
void	ScalarConverter::fromInt(std::string arg)
{
	std::istringstream varInt(arg);
	int nbr;
	if (!(varInt >> nbr))
		displayImpossible(arg);
	else
	{
		if (nbr > 256)
			std::cout << "char: impossible" << std::endl;
		else if (nbr < 38 || nbr > 126)
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
void	ScalarConverter::fromFloat(std::string arg)
{
	std::istringstream varFloat(arg);
	float nbr;
	if (!(varFloat >> nbr))
		displayImpossible(arg);
	else
	{
		if (nbr > 256)
			std::cout << "char: impossible" << std::endl;
		else if (nbr < 38 || nbr > 126)
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
void	ScalarConverter::fromDouble(std::string arg)
{
	std::istringstream varDouble(arg);
	double nbr;
	if (!(varDouble >> nbr))
		displayImpossible(arg);
	else
	{
		if (nbr > 256)
			std::cout << "char: impossible" << std::endl;
		else if (nbr < 38 || nbr > 126)
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

// __ Cast From Pseudo ______ __________________________________________________
// =============================================================================
void	ScalarConverter::fromPseudoFloat(std::string arg)
{
	std::istringstream varFloat(arg);
	float nbr;
	varFloat >> nbr;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << nbr << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(nbr)  << std::endl;
}

// __ Cast From Pseudo ______ __________________________________________________
// =============================================================================
void	ScalarConverter::fromPseudoDouble(std::string arg)
{
	std::istringstream varDouble(arg);
	double nbr;
	varDouble >> nbr;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double: " << nbr << std::endl;
}

// __ ScalarConverter Convert __________________________________________________
// =============================================================================
void ScalarConverter::convert(std::string argument)
{
	e_type type;

	type = getType(argument);
	if (type == FLOAT || type == PSEUDOFLOAT)
			argument.erase(argument.length() - 1);
	void	(*fun[7])(std::string) = {displayImpossible, fromChar, fromInt,
									fromFloat, fromDouble, fromPseudoFloat,
									fromPseudoDouble};
	e_type dataType[7] = {STRING, CHAR, INT, FLOAT, DOUBLE, PSEUDOFLOAT, PSEUDODOUBLE};
	for (int i = 0; i < 7; i++)
	{
		if (type == dataType[i])
			(*fun[i])(argument);
	}
}
