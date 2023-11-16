#include "ScalarConverter.hpp"
#include <string>
#include <sstream>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}


void ScalarConverter::convert(std::string argument)
{
	std::istringstream varFloat(argument);
	char c;
	int a;
	float f;
	double d;
	if (!(varFloat >> f))
	{	
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		c = static_cast<float>(f);
		a = static_cast<int>(f);
		d = static_cast<float>(f) / 1.0;
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << a << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}
