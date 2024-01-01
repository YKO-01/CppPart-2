/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyException.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:39:03 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/23 18:46:00 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYEXCEPTION_HPP
#define MYEXCEPTION_HPP

#include <iostream>

class MyException : public std::exception
{
	private:
		std::string err;
	public :
		MyException();
		MyException(std::string error);
		virtual ~MyException() throw();
		virtual const char* what() const throw();
};

#endif
