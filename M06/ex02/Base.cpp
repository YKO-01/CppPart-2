/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:25:28 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/21 12:09:18 by ayakoubi         ###   ########.fr       */
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

Base	*generate(void)
{
	Base *b = new C();
	return (b);
}	

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
