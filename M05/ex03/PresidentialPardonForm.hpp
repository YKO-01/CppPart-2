/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:51:34 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/10/21 09:52:23 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
	 private:
		std::string target;
		int sign;
		int exec;
	 public:
		 PresidentialPardonForm();
		 PresidentialPardonForm(std::string target);
		 PresidentialPardonForm(const PresidentialPardonForm& copy);
		 ~PresidentialPardonForm();
		 PresidentialPardonForm& operator = (const PresidentialPardonForm& copy);
		 void	execute(const Bureaucrat &executer) const;

};

#endif
