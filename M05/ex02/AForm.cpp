/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:27:43 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/24 09:47:38 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// __ Constructor & Destructor _________________________________________________
// =============================================================================
AForm::AForm(): name("none"), sign(false), grade_sign(0), grade_exec(0)
{
}

AForm::AForm(std::string name, int gSign, int gExec): name(name), grade_sign(gSign), grade_exec(gExec)
{
	sign = false;
}

AForm::AForm(const AForm& copy): name(copy.name), grade_sign(copy.grade_sign), grade_exec(copy.grade_exec)
{
	*this = copy;
}

AForm::~AForm()
{
}

// __ Operators ________________________________________________________________
// =============================================================================
AForm&	AForm::operator=(const AForm& copy)
{
	this->sign = copy.sign;
	return (*this);
}

std::ostream&	operator << (std::ostream& out, const AForm& instance)
{
	out << instance.getName() << std::endl;
	out << instance.getSign() << std::endl;
	out << instance.getGradeSign() << std::endl;
	out << instance.getGradeExec() << std::endl;
	return (out);
}

// __ Throw Exception __________________________________________________________
// =============================================================================
const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Exception: in GradeToohighException");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Exception: in GradeTooLowException");
}

// __ Get (Name, sign, Gradesign, GradeExec) ___________________________________
// =============================================================================
std::string	AForm::getName() const
{
	return (this->name);
}

bool AForm::getSign() const
{
	return (this->sign);
}

int AForm::getGradeSign() const
{
	return (this->grade_sign);
}

int AForm::getGradeExec() const
{
	return (this->grade_exec);
}

// __ AForm Be signed ___________________________________________________________
// =============================================================================
void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->grade_sign > bureaucrat.getGrade())
		this->sign = true;
	else 
		throw AForm::GradeTooHighException();
}
