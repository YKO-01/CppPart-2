/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParsingFile.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:46:03 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/23 19:28:20 by ayakoubi         ###   ########.fr       */
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
	
		bool	openFile(std::ifstream& file, char *arg);
		void	parsingLine(std::string line);
		void	splitLine(std::string line, int i, int j, char **str, char c);
		void	handlingErrors(std::string line, t_data *data);
		bool	validFormat(std::string str, std::string format);
		void	checkValues(std::string line, t_data *data);
};



#endif 
