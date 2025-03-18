/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 09:51:38 by arissane          #+#    #+#             */
/*   Updated: 2025/03/16 13:49:11 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain*	_brain;
	public:
		Dog();
		Dog(const std::string& customType);
		Dog(const Dog& source);
		~Dog();

		Dog&	operator = (const Dog& source);

		void	makeSound() const override;
		Brain*	getBrain();
};

#endif
