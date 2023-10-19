/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:27:43 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/10/19 10:36:01 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("none"), sign(false), grade_sign(0), grade_exec(0)
{
}

Form::Form(std::string name, bool sign, int grade_sign, int grade_exec)
{
	this->name = name;
	this->sing = false;
	this->grade_sign = grade_sign;
	this->grade_exec = grade_exec;
}

Form::Form(const Form& copy)
{
	*this = copy;
}

Form&	Form::operator=(const Form& copy)
{
	this->sign = copy. sign;
	return (*this);
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

std::string Form::getSign() const
{
	return (this->sign);
}

std::string Form::getGradeSign() const
{
	return (this->grade_sign);
}

std::string Form::getGradeExec() const
{
	return (this->grade_exec);
}
