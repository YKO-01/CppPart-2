/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyException.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:17:17 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/23 18:46:27 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyException.hpp"

// __ Constructor & Destructor _________________________________________________
// =============================================================================
MyException::MyException()
{
}

MyException::MyException(std::string error) : err(error)
{
}

MyException::~MyException() throw()
{
}

// __ What Overide _____________________________________________________________
// =============================================================================
const char*	MyException::what() const throw()
{
	return (this->err.c_str());
}
