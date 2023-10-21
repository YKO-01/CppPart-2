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

class PresidentialPardonForm
{
	 private:

	 public:
		 PresidentialPardonForm();
		 PresidentialPardonForm(const PresidentialPardonForm& copy);
		 ~PresidentialPardonForm();
		 PresidentialPardonForm& operator = (const PresidentialPardonForm& copy);

};

std::ostream& operator << (std::ostream& out, const PresidentialPardonForm& instance);

#endif
