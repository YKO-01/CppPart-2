/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParsingArg.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:07:53 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/02/18 09:45:18 by ayakoubi         ###   ########.fr       */
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
	public:
		ParsingArg();
		~ParsingArg();

		void	validArgument(char **arg);

};


#endif
