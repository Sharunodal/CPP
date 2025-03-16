/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:25:01 by arissane          #+#    #+#             */
/*   Updated: 2025/03/16 12:03:03 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal {
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const std::string& customType);
		WrongAnimal(const WrongAnimal& source);
		virtual ~WrongAnimal();

		WrongAnimal&	operator = (const WrongAnimal& source);

		void		makeSound() const;
		std::string	getType() const;
};

#endif
