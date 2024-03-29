/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:40:21 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/24 10:03:17 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class AForm;

class Intern
{
	public :
		Intern();
		Intern(const Intern& copy);
		~Intern();
		Intern& operator = (const Intern& copy);
		AForm*	makeForm(std::string name, std::string target);

};

#endif
