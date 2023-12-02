/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:07:07 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/02 09:55:49 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	ScalarConverter sc;
	sc.convert(av[1]);
	//std::cout << "hello word" << std::endl;
	return (0);
}
