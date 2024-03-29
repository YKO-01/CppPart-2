/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:44:04 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/02/26 18:50:54 by ayakoubi         ###   ########.fr       */
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
		std::cout << "invalid head: " << line  << std::endl << "The correct Head : date | value " << std::endl;
	while (std::getline(file, line))
	{
		if (line.empty())
			std::cerr << "Error: bad input => " << std::endl;
		else
		{
			pfile.getDateAndBtc(line, date, btc);
			try
			{
				pfile.handlingErrors(line, &data);
	   			pfile.checkValues(line, &data);
				date.erase(date.length() - 1);
				btc.erase(0, 1);
				btcEx.getAmount(date, btc);
			}
			catch (std::exception& e)
			{
				std::cerr << "Error: " << e.what()  << std::endl;
			}
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
