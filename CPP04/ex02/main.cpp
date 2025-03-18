/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:22:37 by arissane          #+#    #+#             */
/*   Updated: 2025/03/18 08:40:03 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main()
{
	std::cout << CYAN << "Example test;\nconst Animal* j = new Dog();\nconst Animal* i = new Cat();\ndelete j;\ndelete i;" << DEFAULT << std::endl;
	const Animal* j = nullptr;
	const Animal* i = nullptr;
	try
	{
		j = new Dog();
		i = new Cat();
	}
	catch (const std::bad_alloc& error)
	{
		std::cerr << "Allocation failure: " << error.what() << std::endl;
		if (j != nullptr)
		{
			delete (j);
		}
		if (i != nullptr)
		{
			delete (i);
		}
		return 1;
	}
	std::cout << CYAN << "If j && i are not null, makeSound" << DEFAULT << std::endl;
	if (j != nullptr && i != nullptr)
	{
		j->makeSound();
		i->makeSound();
	}
	delete j;
	delete i;

	std::cout << CYAN << "\nAnimal array[8];" << DEFAULT << std::endl;
	Animal* array[8];

	try
	{
		for (int k = 0; k < 4; k++)
		{
			array[k] = new Dog();
		}
		for (int k = 4; k < 8; k++)
		{
			array[k] = new Cat();
		}
	}
	catch(const std::exception& error)
	{
		std::cerr << "Allocation failure: " << error.what() << std::endl;
		for (int k = 0; k < 8; k++)
		{
			if (array[k] != nullptr)
			{
				delete array[k];
			}
		}
		return 1;
	}
	for (int k = 0; k < 8; k++)
	{
		delete array[k];
	}

	std::cout << CYAN << "\nCat A;\nDog C;" << DEFAULT << std::endl;
	Cat	A;
	Dog	C;
	std::cout << CYAN << "Cat A idea at brain._ideas[0]" << DEFAULT << std::endl;
	A.getBrain()->getIdea(0);
	std::cout << CYAN << "Dog C idea at brain._ideas[0]" << DEFAULT << std::endl;
	C.getBrain()->getIdea(0);
	std::cout << CYAN << "Cat A add idea to brain._ideas[0]" << DEFAULT << std::endl;
	A.getBrain()->setIdea(0, "Sleep");
	std::cout << CYAN << "Dog C add idea to brain._ideas[0]" << DEFAULT << std::endl;
	C.getBrain()->setIdea(0, "Go for a walk");
	std::cout << CYAN << "Cat A idea at brain._ideas[0]" << DEFAULT << std::endl;
	A.getBrain()->getIdea(0);
	std::cout << CYAN << "Dog C idea at brain._ideas[0]" << DEFAULT << std::endl;
	C.getBrain()->getIdea(0);
	std::cout << CYAN << "Cat B(A);\nDog D = Dog();\nD = C;" << DEFAULT << std::endl;
	Cat	B(A);
	Dog	D = Dog();
	D = C;
	std::cout << CYAN << "Cat B get idea at brain._ideas[0]" << DEFAULT << std::endl;
	B.getBrain()->getIdea(0);
	std::cout << CYAN << "Dog D get idea at brain._ideas[0]" << DEFAULT << std::endl;
	D.getBrain()->getIdea(0);
	std::cout << CYAN << "A,B,C,D makeSound" << DEFAULT << std::endl;
	A.makeSound();
	B.makeSound();
	C.makeSound();
	D.makeSound();

	return 0;
}