/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:16:28 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/05 00:52:46 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <deque>

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
