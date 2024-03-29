/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:49:16 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/24 09:47:50 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUEStForm_HPP
#define ROBOTOMYREQUEStForm_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
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
		void	execute(Bureaucrat const &executer) const;	
};


#endif
