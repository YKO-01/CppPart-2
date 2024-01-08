/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParsingArg.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:07:53 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/05 18:44:49 by ayakoubi         ###   ########.fr       */
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

		void	validArgument(char **arg);
		void	scanArgument(char **arg);
		void	checkMatters(std::string arg);
		void	validOperation(std::string arg);
		int		isoperator(char c);

};


#endif
