/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:06:43 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/24 12:38:53 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
#define SCALARCONVERTER


#include <iostream>


typedef enum t_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOFLOAT,
	PSEUDODOUBLE,
	STRING
}	e_type;

class ScalarConverter
{
	public :
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator = (const ScalarConverter& copy);

		static bool	checkConvert(std::string arg);
		static e_type	getType(std::string arg);
		static void	displayImpossible(std::string arg);
		
		static void	fromChar(std::string arg);
		static void	fromInt(std::string arg);
		static void	fromFloat(std::string arg);
		static void	fromDouble(std::string arg);
		static void	fromPseudoFloat(std::string arg);
		static void	fromPseudoDouble(std::string arg);

		static void convert(std::string argument);


};

#endif
