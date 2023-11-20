/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:41:22 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/11/20 17:42:05 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Serializer s;
	Data data;
	data.nbr = 10;
	uintptr_t Iptr = s.serialize(&data);
	std::cout << &data << std::endl;
	std::cout << Iptr << std::endl;
	Data *ptr;
	ptr = s.deserialize(Iptr);
	std::cout << ptr->nbr << std::endl;
	std::cout << ptr << std::endl;
	return (0);
}
