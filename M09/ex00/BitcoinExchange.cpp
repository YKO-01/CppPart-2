/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:24:45 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/25 20:28:59 by ayakoubi         ###   ########.fr       */
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

// __ fill Map _________________________________________________________________
// =============================================================================

void	BitcoinExchange::getAmount(std::string date, std::string btc)
{
	(void) date;
	(void) btc;
	std::map<std::string, float>::iterator it;
	it = btcMap.begin();
	size_t	i;
	i = -1;
	while (++i < btcMap.size())
	{
		if (it->first == date)
			break;
		it++;
	}
	float btcnbr = std::stof(btc.c_str());
	std::cout << date << " => " << btcnbr * it->second << std::endl;
}	
