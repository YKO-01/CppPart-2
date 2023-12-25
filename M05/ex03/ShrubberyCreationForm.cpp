/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:53:19 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/17 15:07:59 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
 
// __ Constructor & Destructor _________________________________________________
// =============================================================================
ShrubberyCreationForm::ShrubberyCreationForm() : sign(145), exec(137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), target(target), sign(145), exec(137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// __ Operators ________________________________________________________________
// =============================================================================
ShrubberyCreationForm&	ShrubberyCreationForm::operator = (const ShrubberyCreationForm& copy)
{
	sign = copy.sign;
	exec = copy.exec;
	return (*this);
}

// __ Shrubbery Execute ________________________________________________________
// =============================================================================
void	ShrubberyCreationForm::execute(Bureaucrat const &executer) const
{
	if (executer.getGrade() <= sign && getSign() == true)
	{
		std::ofstream outfile;
		outfile.open(this->target + "_shrubbery");
		if (!outfile.is_open())
		{
			std::cout << "error in openfile" << std::endl;
			return ;
		}
		int height = 4;
		int tage = -1;
		int	i;
		int j;
		int k;
		int width = 0;
		int margin = 2;
		std::string content;
		while (tage++ < 2)
		{
			i = 0;
    		while (i++ <= height)
			{
				j = 0;
				while (j++ <= height - i + margin)
					content += " ";
				k = 0;
				while (k++ <= (2 * i - 1 + (width * 2)))
					content += "*";
				content += "\n";
			}
			width++;
			margin--;
		}
		for (i = 0; i <= height - 1 + width; i++)
		{
			content += " ";
		}
		content +=  "|\n";
		outfile << content;
		outfile.close();
	}
	else
		throw GradeTooHighException();
}
