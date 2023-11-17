#include "ScalarConverter.hpp"
#include <string>
#include <sstream>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}


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
	

std::string getType(std::string arg)
{
	int len = (int)arg.length() - 1;
	if (len == 0 && (arg[0] < '0' || arg[0] > '9'))
		return ("char");
	if (arg[len] == 'f')
		return ("flaot");
	if (find(arg.begin(), arg.end(), '.') != arg.end())
		return ("double");
	return ("int");
}

void	fromChar(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	fromInt(std::string arg)
{
	std::istringstream varInt(arg);
	int nbr;
	if (!(varInt >> nbr))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	if (nbr < 38 || nbr > 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(nbr) << std::endl;
	std::cout << "int: " << nbr << std::endl;
	std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;

}
			

void ScalarConverter::convert(std::string argument)
{
	std::string type;
	if (checkConvert(argument) == false)
	{	
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		type = getType(argument);
		std::cout << type << std::endl;
		if (type == "char")
			fromChar(argument[0]);
		if (type == "int")
			fromInt(argument);
	/*	if (type == "float")
			fromFloat(argment);
		if (type == "double")
			fromdouble(argument);*/
	}	
}
