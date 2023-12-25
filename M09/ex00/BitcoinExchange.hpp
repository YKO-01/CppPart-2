/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:37:49 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/25 19:53:41 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>

class BitcoinExchange
{
	private :
		std::map<std::string, float> btcMap;

	public	:
		BitcoinExchange();
		~BitcoinExchange();
		
		void	fillMap(std::ifstream& file);
		void	getAmount(std::string date, std::string btc); 

};


#endif
