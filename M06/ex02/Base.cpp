/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:25:28 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/22 09:21:01 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
Base::Base()
{
}

Base::~Base()
{
}

// __ Generate ________________________________________________________________
// ============================================================================
Base	*generate(void)
{
	Base *b = new A();
	return (b);
}

// __ Identify ________________________________________________________________
// ============================================================================
void	identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);
	if (a != NULL)
		std::cout << "type of the object pointed by p : A" << std::endl;
	else if (b != NULL)
		std::cout << "type of the object pointed by p : B" << std::endl;
	else if (c != NULL)
		std::cout << "type of the object pointed by p : C" << std::endl;
}

// __ Identify Ref ____________________________________________________________
// ============================================================================
void	identifyRef(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "type of the object pointed by p : A" << std::endl;
	}
	catch (...)
	{
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "type of the object pointed by p : B" << std::endl;
	}
	catch (...)
	{
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "type of the object pointed by p : C" << std::endl;
	}
	catch (...)
	{
	}
}
