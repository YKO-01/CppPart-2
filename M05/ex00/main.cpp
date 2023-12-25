/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:29:26 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/17 16:09:18 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{

	try
	{
		{
			Bureaucrat b1("bureau1", 149);
			b1.decrement();
			std::cout << b1 << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << "===========================" << std::endl;
		try
	{
		{
			Bureaucrat b2("bureau2", 2);
			b2.increment();
			std::cout << b2 << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}


	return (0);
}
