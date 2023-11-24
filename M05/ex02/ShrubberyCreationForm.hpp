/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:41:51 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/24 09:48:23 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIOnForm_HPP
#define SHRUBBERYCREATIOnForm_HPP

#include "AForm.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm
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

