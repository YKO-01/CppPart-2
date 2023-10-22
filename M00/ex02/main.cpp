/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:30:22 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/10/22 13:40:16 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
int main(void)
{

	try
	{
		Bureaucrat b("hello", 138);
		ShrubberyCreationForm s;
		Form *f = new ShrubberyCreationForm();

		//Form	f("form", false, 16, 3);
		//std::cout << f << std::endl;
		//std::cout << b << std::endl;
		//f.signForm(f);
		b.executeForm(*f);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}


	return (0);
}
