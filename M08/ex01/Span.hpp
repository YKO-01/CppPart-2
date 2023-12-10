/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:53:50 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/10 09:45:28 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private :
		unsigned int N;
		std::vector<int> numbers;
	public :
		Span();
		Span(unsigned int n);
		Span(const Span& copy);
		~Span();
		Span&	operator = (const Span& copy);

		void	addNumber(int nbr);
		int		shortestSpan();
		int		longestSpan();
		void	printVector();	
};
		



#endif
