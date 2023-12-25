/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:32:30 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/25 09:26:32 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// __ Constructor & Destructor _________________________________________________
// =============================================================================
Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& copy)
{
	*this = copy;
}

Serializer::~Serializer()
{
}

// __ Assignemet Operator ______________________________________________________
// =============================================================================
Serializer&	Serializer::operator=(const Serializer& copy)
{
	(void) copy;
	return (*this);
}

// __ Serialize ________________________________________________________________
// =============================================================================
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

// __ Deserialize ______________________________________________________________
// =============================================================================
Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
