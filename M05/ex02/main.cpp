/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:30:22 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/04 19:44:29 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	AForm *f = NULL;
	try
	{
		Bureaucrat b("contable", 35);
		f = new ShrubberyCreationForm("shrubbery");
		b.executeAForm(*f);
		delete f;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
		delete f;
	}
	std::cout << "===============================" << std::endl;
	try
	{
		Bureaucrat b("contable", 35);
		f = new RobotomyRequestForm("robot");
		b.executeAForm(*f);
		delete f;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
		delete f;
	}
	std::cout << "===============================" << std::endl;
	try
	{
		Bureaucrat b("contable", 35);
		f = new PresidentialPardonForm("president");
		b.executeAForm(*f);
		delete f;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
		delete f;
	}
	return (0);
}
