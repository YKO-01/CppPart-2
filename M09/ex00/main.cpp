/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:44:04 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/15 15:24:36 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	parsingLine(std::string line)
{
	char *str[3];

	int i;
	int j;
	i = -1;
	while (++i < line.lenght() && line[i] == '-');
	str[j] = new char[i];
	if (str


		
}



int main(int ac, char **av)
{
	std::string line;
	std::ifstream file;
	if (ac != 2)
		return (0);
	file.open(av[1]);
	if(!file.is_open())
	{
		std::cerr << "can't open this file " << av[1] << std::endl;
		return (0);
	}
	std::getline(file, line); 
	if (line != "date | value")
	{
		std::cerr << "this file not exists" << std::endl;
		return (0);
	}
	while (std::getline(file, line))
	{
		parsingLine(line);
	}
	return (0);
}
