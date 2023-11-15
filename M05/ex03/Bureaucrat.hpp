/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:29:56 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/14 12:18:37 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
#define BUREAUCRAT


#include <iostream>
class Form;
#include "AForm.hpp"

class Bureaucrat
{
	private:
		const std::string name;
		int	grade;
		static int counter;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();
		Bureaucrat&	operator = (const Bureaucrat& copy);
		std::string	getName() const;
		int			getGrade() const;
		void		increment();
		void		decrement();
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		void	signForm(Form& form) const;
		void	executeForm(Form const &form);
		int		getCounter() const;
};

std::ostream& operator << (std::ostream& out, const Bureaucrat& instance);

#endif
