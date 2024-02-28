#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP


// __ Constructors & Destructor ________________________________________________
// =============================================================================
template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& copy)
{
	*this = copy;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	this->c.clear();
}

// __ Assignement Opertator ____________________________________________________
// =============================================================================
template <typename T>
MutantStack<T>&	MutantStack<T>::operator = (const MutantStack& copy)
{
	this->c = copy.c;
	return (*this);
}

// __ Iterator begin() _________________________________________________________
// =============================================================================
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

// __ Iterator end() ___________________________________________________________
// =============================================================================
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

#endif
