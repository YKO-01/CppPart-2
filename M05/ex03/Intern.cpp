/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:41:05 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/16 11:10:02 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//===== constructors & destructor =============================
Intern::Intern()
{
}

Intern::Intern(const Intern& copy)
{
    *this = copy;
}

Intern::~Intern()
{
    
}

//===== operators ==============================================
Intern&	Intern::operator = (const Intern& copy)
{
    (void) copy;
    return (*this);
}


Form*   Intern::makeForm(std::string name, std::string target)
{
    int i;
	int ret;
    Form *form[3]; 
    form[0] = new ShrubberyCreationForm(target);
    form[1] = new RobotomyRequestForm(target);
    form[2] = new PresidentialPardonForm(target);
    
    std::string array[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    i = -1;
	ret = 0;
    while (++i < 3)
    {
        if (name == array[i])
            ret = i;
		else
		{
			delete form[i];
			form[i] = NULL;
		}
    }
    return (form[ret]);
}