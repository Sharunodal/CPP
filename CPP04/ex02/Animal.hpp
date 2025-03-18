/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:25:07 by arissane          #+#    #+#             */
/*   Updated: 2025/03/18 11:21:41 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include <string>

# define CYAN "\033[1;36m"
# define DEFAULT "\033[0;0m"

class Animal {
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const std::string& customType);
		Animal(const Animal& source);
		virtual ~Animal();

		Animal&	operator = (const Animal& source);

		virtual void	makeSound() const = 0;
		std::string	getType() const;
};

#endif
