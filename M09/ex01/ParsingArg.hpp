/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParsingArg.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:07:53 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/02/25 21:56:34 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSINGARG_HPP
#define PARSINGARG_HPP

#include <iostream>
#include <cctype>
#include <vector>
#include "MyException.hpp"

class ParsingArg
{
	private :
		std::vector<int>	arr;
	public:
		ParsingArg();
		~ParsingArg();

		void	validArgument(std::string arg);
		void	scanArgument(std::string arg);
		void	checkMatters(std::string arg);
		void	validOperation(std::string arg);
		int		isoperator(char c);

};


#endif
