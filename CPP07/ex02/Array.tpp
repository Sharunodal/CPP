#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : length( 0 ), array( nullptr )
{}

template <typename T>
Array<T>::Array( const unsigned int n )
{
	length = n;
	array = new T[n]();
}

template <typename T>
Array<T>::Array( const Array& source )
{
	if ( source.size() != 0 )
	{
		length = source.size();
		array = new T[length];
		for ( unsigned int i = 0; i < length; i++ )
		{
			array[i] = source.array[i];
		}
	}
	else
	{
		this->length = 0;
		this->array = nullptr;
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
Array<T>& Array<T>::operator=( const Array<T>& source )
{
	if ( this != &source )
	{
		delete[] *this;
		length = source.size();
		for ( unsigned int i = 0; i < length; i++ )
		{
			array[i] = source.array[i];
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if ( index >= size() )
	{
		throw std::out_of_range( "index is out of range" );
	}
	return array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if ( index >= size() )
	{
		throw std::out_of_range( "index is out of range" );
	}
	return array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return length;
}

#endif
