/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:24:45 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/02/26 18:04:42 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>

// __ Constructor & Destructor _________________________________________________
// =============================================================================
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
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
		std::istringstream ss(btcString);
		ss >> btc;
		btcMap.insert(std::make_pair(date, btc));	
	}
}

// __ fill Map _________________________________________________________________
// =============================================================================

void	BitcoinExchange::getAmount(std::string date, std::string btc)
{
	std::map<std::string, float>::iterator it;
	std::istringstream	ss(btc);
	float				btcNbr;

	it = btcMap.lower_bound(date);
	ss >> btcNbr;
	std::cout << date << " => " << btcNbr << " = " << it->second * btcNbr << std::endl;
}	
