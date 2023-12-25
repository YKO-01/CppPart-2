/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:44:04 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/25 20:55:57 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "ParsingFile.hpp"
#include "MyException.hpp"

void	readFile(std::ifstream& file, BitcoinExchange btcEx)
{
	std::string		line;
	std::string		date;
	std::string		btc;
	ParsingFile		pfile;
	t_data			data;

	std::getline(file, line); 
	if (!pfile.validFormat(line, "date | value"))
		throw MyException("bad input => " + line);
	while (std::getline(file, date, '|') && std::getline(file, btc))
	{
		line = date + "|" + btc;
		try
		{
			pfile.handlingErrors(line, &data);
	   		pfile.checkValues(line, &data);
			date.erase(date.length() - 1);
			btc.erase(0, 1);
			std::cout << date << "," << btc << std::endl;
			btcEx.getAmount(date, btc);

		}
		catch (std::exception& e)
		{
			std::cerr << "Error: " << e.what()  << std::endl;
		}
	}
}

int main(int ac, char **av)
{
	std::ifstream file(av[1]);
	std::ifstream dataFile("data.csv");
	BitcoinExchange btcEx;

	try
	{
		if (ac != 2)
			throw MyException("could not open file.");
		if (!dataFile.is_open())
			throw MyException("can't open this file.");
		btcEx.fillMap(dataFile);
		if (!file.is_open())
			throw MyException("can't open this file.");
		readFile(file, btcEx);
	}
	catch(std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}	
	return (0);
}
