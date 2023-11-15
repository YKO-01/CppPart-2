/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:49:16 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/14 12:48:09 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public Form
{
	 private:
		std::string target;
		int sign;
		int exec;
	 public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator = (const RobotomyRequestForm& copy);
		std::string	getName() const;
		void	execute(Bureaucrat const &executer) const;	
};


#endif
