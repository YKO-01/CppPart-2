/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:30:09 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/10/19 11:14:37 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("exeption in GradeTooHighException !");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("exeption in GradeTooLowException !");
}

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

void	Bureaucrat::signForm(const Form& form) const
{
	form.beSigned(*this);
	if (getSing == true)
		std::cout << this->getName() << "signed " << form.getName() << std::enld;
	else
		std::cout << this->getName() << "couldn't sign " << form.getName()
			<< "because " << std::endl;
}
