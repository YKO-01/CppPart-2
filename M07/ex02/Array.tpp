/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:53:21 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/12/13 11:16:56 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */ 

#ifndef ARRAY_TPP
#define ARRAY_TPP


template <class T>
Array<T>::Array()
{
	n = 0;
	arr = NULL;
}

template <class T>
Array<T>::Array(unsigned int n)
{
	try
	{
		this->n = n;
		arr = new T[n];
	}
	catch(std::bad_alloc& e)
	{
		std::cout << e.what() << std::endl;
	}
}

template <class T>
Array<T>::Array(const Array& copy)
{
	if (this->n != copy.size())
	{
		this->n = copy.size();
		this->arr = new T[n];
		if (!arr)
			exit(EXIT_FAILURE);
	}
	unsigned int i;
	i = -1;
	while (++i < n)
		this->arr[i] = copy.arr[i];
}

template <class T>
Array<T>::~Array()
{
	delete arr;
}

template <class T>
Array<T>&	Array<T>::operator = (const Array& copy)
{	
	if (this->n != copy.size())
	{
		this->n = copy.size();
		this->arr = new T[n];
		if (!arr)
			exit(EXIT_FAILURE);
	}
	unsigned int i;
	i = -1;
	while (++i < n)
		this->arr[i] = copy.arr[i];
	return (*this);
}

template <class T>
T&	Array<T>::operator [] (int index)
{
	if (index >= (int)n || index < 0)
		throw std::out_of_range("its index out of bound");
	return (arr[index]);
}

template <class T>
unsigned int	Array<T>::size() const
{
	return (n);
}

#endif
