/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:44:04 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/24 12:11:59 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "ParsingFile.hpp"
#include "MyException.hpp"

void	readFile(std::ifstream& file)
{
	std::string		line;
	ParsingFile		pfile;
	t_data			data;

	std::getline(file, line); 
	if (!pfile.validFormat(line, "date | value"))
		throw MyException("bad input => " + line);
	while (std::getline(file, line))
	{
		try
		{
			pfile.handlingErrors(line, &data);
	   		pfile.checkValues(line, &data);
			pfile.parsingLine(line);
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
	std::ifstream fileData("

	try
	{
		if (ac != 2)
			throw MyException("could not open file.");
		if (!file.is_open())
			throw MyException("can't open this file."); 
		readFile(file);
	}
	catch(std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}	
	return (0);
}
