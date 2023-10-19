/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:35:10 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/10/19 10:45:17 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool sign;
		const int grade_sign;
		const int grade_exec;
	public;
		Form();
		Form(const From& copy);
		Form(std::string name, bool sign, int grade_sign, int grade_exec);
		~Form();
		Form&	operator = (const Form& copy);
		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
		std::string getName() const;
		bool		getSign() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
};

std::ostream& operator << (std::ostream& out, const Form& instance);

#endif
