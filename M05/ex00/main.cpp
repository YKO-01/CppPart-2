/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:29:26 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/12 10:29:28 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{

	try
	{
		Bureaucrat b("gym", 138);
		Bureaucrat c(b);
		b.decrement();
		b.increment();
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}


	return (0);
}
