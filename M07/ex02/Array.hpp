/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:53:21 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/04 11:59:15 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array
{
	private:
		T *arr;
		int n;
	public :
		Array() {
			n = 0;
			arr = NULL;
		}
		Array(unsigned int n){
			this->n = n;
			arr = new T[n];
		}
		Array(const Array& copy){
			*this = copy;
		}
		~Array(){
			delete [] arr;
		}
		Array& operator = (const Array& copy){
			int	i;
			i = -1;
			this->n = copy.size();	
			this->arr = new T[n];
			while (++i < n)
				this->arr[i] = copy.arr[i];
			return (*this);
		}
		T& operator [] (int index){
			if (index >= n || index < 0)
				throw throwException();
			return (arr[index]);
		}

		class throwException : public std::exception{
			public :
				virtual const char* what() const throw(){
					return ("its index out of bound");
				}
		};
		
		int	size() const{
			return (n);
		}
};



#endif
