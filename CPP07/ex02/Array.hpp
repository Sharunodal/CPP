/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:02:32 by arissane          #+#    #+#             */
/*   Updated: 2025/04/14 11:09:12 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
	private:
		unsigned int	length;
		T*		array;
	public:
		Array();
		Array( const unsigned int n );
		Array( const Array& source );
		~Array();
		Array&		operator=( const Array& source );
		T&		operator[]( unsigned int index );
		const T&	operator[]( unsigned int index ) const;
		unsigned int	size() const;
};

#endif
