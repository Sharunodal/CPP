/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:43:05 by arissane          #+#    #+#             */
/*   Updated: 2025/03/16 13:38:23 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain& source);
		virtual ~Brain();

		Brain&	operator = (const Brain& source);

		void	setIdea(int index, std::string newIdea);
		void	getIdea(int index);
};

#endif
