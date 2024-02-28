/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParsingFile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:01:36 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/02/25 22:19:41 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParsingFile.hpp"
#include "MyException.hpp"

// __ Constuctor & Destructor __________________________________________________
// =============================================================================
ParsingFile::ParsingFile()
{
}


ParsingFile::~ParsingFile()
{
}

void	ParsingFile::getDateAndBtc(std::string line, std::string &date, std::string &btc)
{
	size_t pos;

	pos = line.find("|");
	if (pos != std::string::npos)
	{
		date = line.substr(0, pos);
		btc = line.substr(pos);
	}
	else
	{
		date = line;
		btc = "";
	}
}

// __ handlingErrors() _________________________________________________________
// =============================================================================
void	ParsingFile::handlingErrors(std::string line, t_data *data)
{
	int count;
	int size;
	int i;

	count = sscanf(line.c_str(), "%d-%d-%d | %f",
					&(data->year), &(data->month), &(data->day), &(data->btc));
	if (count != 4)
		throw MyException("bad input => " + line);
	size = static_cast<int>(line.length());
	if (line[0] == '-' || line[0] == ' ' || line[size - 1] == ' ')
		throw MyException("bad input => " + line);
	i = -1;
	while (++i < size)
	{
		if (line[i] == '-' && line[i + 1] == '-')
			throw MyException("bad input => " + line);
		if (line[i] == ' ' && line[i + 1] == ' ')
			throw MyException("bad input => " + line);
	}
}

// __ validFormat() ____________________________________________________________
// =============================================================================
bool	ParsingFile::validFormat(std::string str, std::string format)
{
	return (str == format);
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
// __ checkValues() ____________________________________________________________
// =============================================================================
void	ParsingFile::checkValues(std::string line, t_data *data)
{
	if (data->year >= 2023 || data->year < 2009)
		throw MyException("bad input => " + line);
	if (data->month < 1 || data->month > 12)
		throw MyException("bad input => " + line);
	if (data->day < 1 || data->day > 31)
		throw MyException("bad input => " + line);
	if (data->month < 8 && !(data->month % 2) && data->day > 30)
		throw MyException("bad input => " + line);
	if (data->month > 7 && data->month % 2 && data->day > 30)
		throw MyException("bad input => " + line);
	int leap = isLeapYear(data->year) ? 29 : 28;
	if (data->month == 2 && data->day > leap)
		throw MyException("bad input => " + line);
	if (data->btc < 0)
		throw MyException("not a positive number.");
	if (data->btc > 1000)
		throw MyException("too large number.");
}


