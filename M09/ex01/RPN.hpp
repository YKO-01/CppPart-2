/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:16:28 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/04 17:29:36 by ayakoubi         ###   ########.fr       */
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
		void	calculate(char *str, int *ret);
};



#endif
