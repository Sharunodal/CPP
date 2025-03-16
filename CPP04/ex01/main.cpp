/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:22:37 by arissane          #+#    #+#             */
/*   Updated: 2025/03/16 13:43:20 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	Animal* array[8];

	for (int k = 0; k < 4; k++)
	{
		array[k] = new Dog();
	}
	for (int k = 4; k < 8; k++)
	{
		array[k] = new Cat();
	}
	for (int k = 0; k < 8; k++)
	{
		delete array[k];
	}

	Cat	A;
	A.getBrain()->setIdea(0, "sleep");
	Cat	B(A);
	B.getBrain()->getIdea(0);

	return 0;
}
