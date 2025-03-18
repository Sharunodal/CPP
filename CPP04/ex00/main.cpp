/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:22:37 by arissane          #+#    #+#             */
/*   Updated: 2025/03/16 12:27:44 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	subjectCode()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;

	return 0;
}

int	wrongAnimalTest()
{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();
	delete i;
	delete meta;

	return 0;
}

void	animalClassTest()
{
	std::cout << CYAN << "Animal def;" << DEFAULT << std::endl;
	Animal	def;
	std::cout << def.getType() << std::endl;
	def.makeSound();

	std::cout << CYAN << "\nAnimal A(\"Hyrax\");" << DEFAULT << std::endl;
	Animal	A("Hyrax");
	std::cout << A.getType() << std::endl;
	A.makeSound();

	std::cout<< CYAN << "\nAnimal B(A);" << DEFAULT << std::endl;
	Animal	B(A);
	std::cout << B.getType() << std::endl;
	B.makeSound();

	std::cout << CYAN << "\nB = def;" << DEFAULT << std::endl;
	B = def;
	std::cout << B.getType() << std::endl;
	B.makeSound();
}

void	catClassTest()
{
	std::cout << CYAN << "\nCat def;" << DEFAULT << std::endl;
	Cat	def;
	std::cout << def.getType() << std::endl;
	def.makeSound();

	std::cout << CYAN << "\nCat A(\"Manul\");" << DEFAULT << std::endl;
	Cat	A("Manul");
	std::cout << A.getType() << std::endl;
	A.makeSound();

	std::cout << CYAN << "\nCat B(A);" << DEFAULT << std::endl;
	Cat	B(A);
	std::cout << B.getType() << std::endl;
	B.makeSound();

	std::cout << CYAN << "\nB = def;" << DEFAULT << std::endl;
	B = def;
	std::cout << B.getType() << std::endl;
	B.makeSound();
}

void	dogClassTest()
{
	std::cout << CYAN << "\nDog def;" << DEFAULT << std::endl;
	Dog	def;
	std::cout << def.getType() << std::endl;
	def.makeSound();

	std::cout << CYAN << "\nDog A(\"Wolf\");" << DEFAULT << std::endl;
	Dog	A("Wolf");
	std::cout << A.getType() << std::endl;
	A.makeSound();

	std::cout << CYAN << "\nDog B(A);" << DEFAULT << std::endl;
	Dog	B(A);
	std::cout << B.getType() << std::endl;
	B.makeSound();

	std::cout << CYAN << "\nB = def;" << DEFAULT << std::endl;
	B = def;
	std::cout << B.getType() << std::endl;
	B.makeSound();
}

void	wrongAnimalClassTest()
{
	std::cout << CYAN << "\nWrongAnimal def;" << DEFAULT << std::endl;
	WrongAnimal	def;
	std::cout << def.getType() << std::endl;
	def.makeSound();

	std::cout << CYAN << "\nWrongAnimal A(\"Hyrax\");" << DEFAULT << std::endl;
	WrongAnimal	A("Hyrax");
	std::cout << A.getType() << std::endl;
	A.makeSound();

	std::cout << CYAN << "\nWrongAnimal B(A);" << DEFAULT << std::endl;
	WrongAnimal	B(A);
	std::cout << B.getType() << std::endl;
	B.makeSound();

	std::cout << CYAN << "\nB = def;" << DEFAULT << std::endl;
	B = def;
	std::cout << B.getType() << std::endl;
	B.makeSound();
}

void	wrongCatClassTest()
{
	std::cout << CYAN << "\nWrongCat def;" << DEFAULT << std::endl;
	WrongCat	def;
	std::cout << def.getType() << std::endl;
	def.makeSound();
	std::cout << CYAN << "Since def is a WrongCat object instead of a pointer or a reference to the base class, it is able to use the makeSound() function of the Wrongcat class instead of the WrongAnimal one." << DEFAULT << std::endl;

	std::cout << CYAN << "\nWrongCat A(\"Manul\");" << DEFAULT << std::endl;
	WrongCat	A("Manul");
	std::cout << A.getType() << std::endl;
	A.makeSound();

	std::cout << CYAN << "\nWrongCat B(A);" << DEFAULT << std::endl;
	WrongCat	B(A);
	std::cout << B.getType() << std::endl;
	B.makeSound();

	std::cout << CYAN << "\nB = def;" << DEFAULT << std::endl;
	B = def;
	std::cout << B.getType() << std::endl;
	B.makeSound();
}

int	main()
{
	std::cout << CYAN << "Tests from the subject:" << DEFAULT << std::endl;
	subjectCode();
	std::cout << CYAN << "\nTests with WrongAnimal:" << DEFAULT << std::endl;
	wrongAnimalTest();
	std::cout << CYAN << "\nExtra tests:" << DEFAULT << std::endl;
	animalClassTest();
	catClassTest();
	dogClassTest();
	wrongAnimalClassTest();
	wrongCatClassTest();

	return 0;
}
