#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& source) : std::stack<T>(source)
{
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& source)
{
	if (this != &source)
	{
		std::stack<T>::operator=(source);
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return this->c.end();
}

#endif
