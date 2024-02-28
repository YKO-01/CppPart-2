/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:16:28 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/02/25 01:16:36 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <deque>
#include "MyException.hpp"
class RPN
{
	private:
		std::deque<int>		arr;
	public:
		RPN();
		RPN(const RPN& copy);
		~RPN();
		RPN&	operator = (const RPN& copy);
		int		getValue(char c, int first, int second);
		int		getOperator(char c);
		void	calculate(char *str, int *ret);
};



#endif
