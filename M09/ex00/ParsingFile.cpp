/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParsingFile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:01:36 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/23 19:58:08 by ayakoubi         ###   ########.fr       */
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

// __ checkLine() ______________________________________________________________
// =============================================================================
void	ParsingFile::parsingLine(std::string line,) 
{
	char *str[3];
	char *date[4];

	int i;
	int j;
	i = -1;
	j = 0;
	splitLine(line, i, j, str, '|');
	str[2] = NULL;
	splitLine(str[0], i, j, date, '-');
	date[3] = NULL;
	i = -1;
	while (date[++i])
		std::cout << date[i] << std::endl;
}

// __ splitLine() ______________________________________________________________
// =============================================================================
void	ParsingFile::splitLine(std::string line, int i, int j, char **str, char c)
{
	int size;
	int k;
	int count;
	int len;

	size = static_cast<int>(line.length());
	count = i;
	count++;
	while (++i < size && line[i] != c);
	len = i - count;
	str[j] = new char[len];
	k = -1;
	while (++k < len)
		str[j][k] = line[count++];
	if (i < size)
		splitLine(line, i, ++j, str, c);
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
	if (data->month == 2 && data->day > 28)
		throw MyException("bad input => " + line);
	if (data->btc < 0)
		throw MyException("not a positive number.");
	if (data->btc > 1000)
		throw MyException("too large number.");
}

