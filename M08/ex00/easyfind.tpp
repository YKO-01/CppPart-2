#ifndef EASYFIND_TPP
#define EASYFIND_TPP


template <typename T>
T	easyfind(std::vector<T>first, int second)
{
	int i;
	i = -1;
	while (++i < (int)first.size())
	{
		if (first[i] == second)
			return (i);
	}
	throw "element not found";

}

#endif
