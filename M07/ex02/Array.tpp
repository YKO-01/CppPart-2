
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
	int i;
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
	int i;
	i = -1;
	while (++i < n)
		this->arr[i] = copy.arr[i];
	return (*this);
}

template <class T>
T&	Array<T>::operator [] (int index)
{
	if (index >= n || index < 0)
		throw throwException();
	return (arr[index]);
}

template <class T>
const char* Array<T>::throwException::what() const throw()
{
	return ("its index out of bound");
}

template <class T>
int	Array<T>::size() const
{
	return (n);
}

#endif
