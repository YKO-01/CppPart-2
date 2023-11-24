/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:30:22 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/24 09:48:23 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{

	try
	{
		Bureaucrat b("contable", 35);
		AForm *f = new ShrubberyCreationForm("shrubbery");
		b.executeAForm(*f);
		delete f;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << "===============================" << std::endl;
	try
	{
		Bureaucrat b("contable", 35);
		AForm *f = new RobotomyRequestForm("robot");
		b.executeAForm(*f);
		delete f;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << "===============================" << std::endl;
	try
	{
		Bureaucrat b("contable", 35);
		AForm *f = new PresidentialPardonForm("president");
		b.executeAForm(*f);
		delete f;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	return (0);
}
