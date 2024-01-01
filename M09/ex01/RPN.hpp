/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:16:28 by ayakoubi          #+#    #+#             */
/*   Updated: 2024/01/01 01:54:35 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		MutantStack<int>		arr;
	public:
		RPN();
		RPN(const RPN& copy);
		~PRN();
		RPN&	operator = (const RPN& copy);
};



#endif
