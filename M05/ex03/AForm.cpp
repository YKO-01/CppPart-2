/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:27:43 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/14 13:06:56 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form(): name("none"), sign(false), grade_sign(0), grade_exec(0)
{
}

Form::Form(std::string name, int gSign, int gExec): name(name), grade_sign(gSign), grade_exec(gExec)
{
	sign = false;
}

Form::Form(const Form& copy): name(copy.name), grade_sign(copy.grade_sign), grade_exec(copy.grade_exec)
{
	*this = copy;
}

Form&	Form::operator=(const Form& copy)
{
	this->sign = copy.sign;
	return (*this);
}

Form::~Form()
{
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Exception: in GradeToohighException");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Exception: in GradeTooLowException");
}

std::string	Form::getName() const
{
	return (this->name);
}

bool Form::getSign() const
{
	return (this->sign);
}

int Form::getGradeSign() const
{
	return (this->grade_sign);
}

int Form::getGradeExec() const
{
	return (this->grade_exec);
}

std::ostream&	operator << (std::ostream& out, const Form& instance)
{
	out << instance.getName() << std::endl;
	out << instance.getSign() << std::endl;
	out << instance.getGradeSign() << std::endl;
	out << instance.getGradeExec() << std::endl;
	return (out);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->grade_sign > bureaucrat.getGrade())
		this->sign = true;
	else 
		throw Form::GradeTooHighException();
}


