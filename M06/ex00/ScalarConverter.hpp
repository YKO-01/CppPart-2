/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:06:43 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/18 10:06:44 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
#define SCALARCONVERTER


#include <iostream>

class ScalarConverter
{
	public :
		ScalarConverter();
		~ScalarConverter();
		static void convert(std::string argument);

};

#endif
