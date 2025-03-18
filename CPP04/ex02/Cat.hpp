/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:06:15 by arissane          #+#    #+#             */
/*   Updated: 2025/03/16 13:42:15 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain*	_brain;
	public:
		Cat();
		Cat(const std::string& customType);
		Cat(const Cat& source);
		~Cat();

		Cat&	operator = (const Cat& source);

		void	makeSound() const override;
		Brain*	getBrain();
};

#endif
