/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:27:43 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/05 12:42:35 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// __ Constructor & Destructor _________________________________________________
// =============================================================================
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

Form::~Form()
{
}

// __ Operators ________________________________________________________________
// =============================================================================
Form&	Form::operator=(const Form& copy)
{
	this->sign = copy.sign;
	return (*this);
}

std::ostream&	operator << (std::ostream& out, const Form& instance)
{
	out << instance.getName() << std::endl;
	out << instance.getSign() << std::endl;
	out << instance.getGradeSign() << std::endl;
	out << instance.getGradeExec() << std::endl;
	return (out);
}

// __ Throw Exception __________________________________________________________
// =============================================================================
const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Exception: in GradeToohighException");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Exception: in GradeTooLowException");
}

// __ Get (Name, sign, Gradesign, GradeExec) ___________________________________
// =============================================================================
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

// __ Form Be signed ___________________________________________________________
// =============================================================================
void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->grade_sign >= bureaucrat.getGrade())
		this->sign = true;
	else 
		throw Form::GradeTooHighException();
}


