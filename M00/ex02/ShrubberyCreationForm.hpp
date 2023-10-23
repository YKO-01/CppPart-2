/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:41:51 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/10/23 12:30:05 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
class ShrubberyCreationForm : public Form
{
	 private:
		std::string target;
		int	sign;
		int	exec;
	 public:
		 ShrubberyCreationForm();
		 ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		 ShrubberyCreationForm(std::string target);
		 ~ShrubberyCreationForm();
		 ShrubberyCreationForm& operator = (const ShrubberyCreationForm& copy);
		 void	execute(Bureaucrat const &executer) const;

};

#endif

