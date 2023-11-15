/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:50:33 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/14 13:07:47 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//===== constructors & destructor =============================
RobotomyRequestForm::RobotomyRequestForm():target("default"), sign(72), exec(45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, 72, 45)
{
	this->target = target;
	sign = 72;
	exec = 45;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
{
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

//===== operators ==============================================
RobotomyRequestForm&	RobotomyRequestForm::operator = (const RobotomyRequestForm& copy)
{
	this->target = copy.target;
	this->sign = copy.sign;
	this->exec = copy.exec;
	return (*this);
}

std::string RobotomyRequestForm::getName() const
{
	return (this->target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executer) const
{
	if (executer.getGrade() <= sign && executer.getGrade() <= exec)
	{
		if (executer.getCounter() % 2 == 0)
		{
			std::cout << this->target
				<< " has ben robotomized"
				<< std::endl;
		}
		else
			std::cout << "the robotomy failed" << std::endl;
	}
	else
		throw GradeTooHighException();
}
