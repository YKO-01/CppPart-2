/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:52:31 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/24 10:02:17 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// __ constructor & Destructor _________________________________________________
// =============================================================================
PresidentialPardonForm::PresidentialPardonForm() : sign(25), exec(5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
	this->target = target;
	sign = 25;
	exec = 5;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
{
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

// __ Operators ________________________________________________________________
// =============================================================================
PresidentialPardonForm&	PresidentialPardonForm::operator = (const PresidentialPardonForm& copy)
{
	this->target = copy.target;
	this->sign = copy.sign;
	this->exec = copy.exec;
	return (*this);
}

// __ Presidential execute _____________________________________________________
// =============================================================================
void	PresidentialPardonForm::execute(const Bureaucrat &executer) const
{
	if (executer.getGrade() <= sign && executer.getGrade() <= exec)
	{
		std::cout << this->target
			<< " has been pardoned by Zaphod Beeblebrox" << std::endl; 		
	}
	else
		throw GradeTooHighException();
}
