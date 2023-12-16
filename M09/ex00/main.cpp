/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:44:04 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/16 20:28:43 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	split_line(std::string line, int i, int j, char **str)
{
	int size = static_cast<int>(line.length());
	int k;
	int c = i;
	int len;
	c++;
	while (++i < size && line[i] != '-');
	len = i - c;
	str[j] = new char[len];
	k = -1;
	while (++k < len)
		str[j][k] = line[c++];
	if (i < size)
		split_line(line, i, ++j, str);
}



void	parsingLine(std::string line)
{
	char *str[4];

	int i;
	int j;
	i = -1;
	j = 0;
	split_line(line, i, j, str);
	str[3] = NULL;
	i = -1;
	while (str[++i])
		std::cout << str[i] << std::endl;
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
