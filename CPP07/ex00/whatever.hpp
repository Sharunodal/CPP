/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:53:25 by arissane          #+#    #+#             */
/*   Updated: 2025/04/11 14:34:09 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap( T& a, T& b )
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const& min( const T& a, const T& b )
{
	if ( a == b )
	{
		return b;
	}
	else if ( a < b )
	{
		return a;
	}
	else
	{
		return b;
	}
}

template <typename T>
T const& max( const T& a, const T& b )
{
	if ( a == b )
	{
		return b;
	}
	else if ( a > b )
	{
		return a;
	}
	else
	{
		return b;
	}
}

#endif
