/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:35:10 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/15 13:24:48 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

class Bureaucrat;
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool sign;
		const int grade_sign;
		const int grade_exec;
	public:
		Form();
		Form(const Form& copy);
		Form(std::string name, int gSign, int gExec);
		virtual ~Form();
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
		void		beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(Bureaucrat const &executer) const = 0;	
};

std::ostream& operator << (std::ostream& out, const Form& instance);

#endif
