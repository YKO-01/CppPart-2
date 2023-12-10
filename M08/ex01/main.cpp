/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:51:25 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/10 10:43:07 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <time.h>
#include <unistd.h>
int main()
{
	Span sp = Span(10);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(56);
	sp.addNumber(42);
	sp.addNumber(12);
	sp.addNumber(19);
	sp.addNumber(19);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
//	sp.printVector();
	std::cout << "========================" << std::endl;
//	tmp.printVector();
	return (0);
}
