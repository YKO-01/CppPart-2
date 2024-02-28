#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T>
typename T::iterator	easyfind(T &arr, int found)
{
		
	typename T::iterator it = std::find(arr.begin(), arr.end(), found);
		if (it == arr.end())
		throw ("NOT FOUND");
	return it;
}

#endif