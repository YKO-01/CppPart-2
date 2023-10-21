/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:49:16 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/10/21 09:50:17 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm"

class RobotomyRequestForm
{
	 private:

	 public:
		 RobotomyRequestForm();
		 RobotomyRequestForm(const RobotomyRequestForm& copy);
		 ~RobotomyRequestForm();
		 RobotomyRequestForm& operator = (const RobotomyRequestForm& copy);

};

std::ostream& operator << (std::ostream& out, const RobotomyRequestForm& instance);

#endif
