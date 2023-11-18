/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:43:58 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/18 20:34:33 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef struct s_Data
{
	int nbr;
}	Data;

class Serializer
{
	public :
		Serializer();
		~Serializer();
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
}

#endif
