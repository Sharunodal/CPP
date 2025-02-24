/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:49:27 by arissane          #+#    #+#             */
/*   Updated: 2025/02/24 11:47:44 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

# include <string>
# include <iostream>

class Harl
{
	private:
		void			debug( void );
		void			info( void );
		void			warning( void );
		void			error( void );
		static void		(Harl::*functions[])();
		static std::string	levels[];
	public:
		Harl();
		~Harl();
		void			complain( std::string level );
};

#endif
