#include <iostream>
#include <fstream>
#include <string>


int main(void)
{
	std::ifstream file("data.csv");
	std::string line;
	std::string date;
	std::string btc;

	std::getline(file, line);
	int i;
	i = 0;
	while(std::getline(file, date, ',') && std::getline(file, btc))
	{
		std::cout << "date => " << date << "$" << std::endl;
		std::cout << "btc => " << btc << std::endl;
	}
	return (0);
}
