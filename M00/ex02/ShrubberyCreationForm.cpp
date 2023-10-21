/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:53:19 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/10/21 14:27:30 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
 
//===== constructors & destructor =============================
ShrubberyCreationForm::ShrubberyCreationForm() : sign(145), exec(137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

//===== operators ==============================================
ShrubberyCreationForm&	ShrubberyCreationForm::operator = (const ShrubberyCreationForm& copy)
{
	sign = copy.sign;
	exec = copy.exec;
	return (*this);
}
void	ShrubberyCreationForm::execute(Bureaucrat const &executer) const
{
	int i;
	int j;
	int k;
	int tage;
	std::ofstream outfile;
	(void) executer;

	outfile.open(name + "_shrubbery");
	if (!outfile.is_open())
	{
		std::cout << "error in openfile" << std::endl;
		return ;
	}
	i = -1;
	tage = 4;
	k = 0;
	while (i < 0)
	{


	}
}
