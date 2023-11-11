/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:50:33 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/10/21 09:51:23 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//===== constructors & destructor =============================
RobotomyRequestForm::RobotomyRequestForm(): sign(72), exec(45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
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
RobotomyRequestForm&	RobotmyRequestForm::operator = (const RobotomyRequestForm& copy)
{
	this->target = copy.target;
	this->sign = copy.sign;
	this->exec = copy.exec;
	return (*this);
}

void	RobotmyRequestForm::execute(const Bureaucrat &executer) const
{
	if (executer.getGrade() <= sign && executer.getGrade() <= exec)
	{
		std::cout << this->target
			<< " has ben robotomized successfully 50% of the time"
			<< std::endl;
	}
	else
	{
		std::cout << "the robotomy failed" << std::endl;
		throw GradeTooHighExeception();
	}
}
