#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	ScalarConverter sc;
	sc.convert(av[1]);
	//std::cout << "hello word" << std::endl;
	return (0);
}
