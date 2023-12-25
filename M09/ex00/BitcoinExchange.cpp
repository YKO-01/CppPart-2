/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:24:45 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/25 14:45:18 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// __ Constructor & Destructor _________________________________________________
// =============================================================================
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}
template <typename T>
void printMap(T it)
{
	std::cout << it->first << " | " << it->second << std::endl;
}

// __ fill Map _________________________________________________________________
// =============================================================================
void	BitcoinExchange::fillMap(std::ifstream& file)
{
	std::string line;
	std::string date;
	std::string btcString;
	float		btc;

	std::getline(file, line);
	while (std::getline(file, date, ',') && std::getline(file, btcString))
	{
		btc = std::atof(btcString.c_str());
		btcMap.insert(std::make_pair(date, btc));
	}
	std::map<std::string, float>::iterator	it;
}

