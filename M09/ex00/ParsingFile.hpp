/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParsingFile.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:46:03 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/02/25 22:20:01 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSINGFILE_HPP
#define PARSINGFILE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <sstream>


typedef struct s_data
{
	int year;
	int month;
	int day;
	float	btc;
}	t_data;

class ParsingFile
{
	public :
		ParsingFile();
		~ParsingFile();
	
		void	getDateAndBtc(std::string line, std::string &date, std::string &btc);
		void	handlingErrors(std::string line, t_data *data);
		bool	validFormat(std::string str, std::string format);
		void	checkValues(std::string line, t_data *data);
};



#endif 
