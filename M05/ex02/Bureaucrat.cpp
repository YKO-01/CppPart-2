/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:30:09 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/18 17:12:13 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int Bureaucrat::counter = 0;

// __ Constructor & Destructor _________________________________________________
// =============================================================================
Bureaucrat::Bureaucrat() : name("none"), grade(1)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (this->grade < 1)
	   	throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
}

// __ Operators ________________________________________________________________
// =============================================================================
Bureaucrat&		Bureaucrat::operator=(const Bureaucrat& copy)
{
	this->grade = copy.grade;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& instance)
{
	out << instance.getName() << ", bureaucrat grade " << instance.getGrade();
	return (out);
}

// __ Bureaucrat Get Name ______________________________________________________
// =============================================================================
std::string	Bureaucrat::getName() const
{
	return (this->name);
}

// __ Bureaucrat Get Grade _____________________________________________________
// =============================================================================
int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

// __ Bureaucrat Get Counter ___________________________________________________
// =============================================================================
int	Bureaucrat::getCounter() const
{
	return (this->counter);
}

// __ Throw Exception __________________________________________________________
// =============================================================================
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("exeption in GradeTooHighException !");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("exeption in GradeTooLowException !");
}

// __ Increment & Decrement ____________________________________________________
// =============================================================================
void	Bureaucrat::increment()
{
	if (this->getGrade() < 150)
	{
		this->grade++;
		return;
	}
	throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::decrement()
{
	if (this->getGrade() > 1)
	{
		this->grade--;
		return ;
	}
	throw Bureaucrat::GradeTooHighException();
}

// __ Sign Form ________________________________________________________________
// =============================================================================
void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		if (form.getSign() == true)
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

// __ Execute Form _____________________________________________________________
// =============================================================================
void	Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		this->counter++;
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->getName() << " couldn't executed " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

