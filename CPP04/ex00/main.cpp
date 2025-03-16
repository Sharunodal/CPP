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
	std::cout << "Animal def" << std::endl;
	Animal	def;
	std::cout << def.getType() << std::endl;
	def.makeSound();

	std::cout << "\nAnimal A(\"Hyrax\")" << std::endl;
	Animal	A("Hyrax");
	std::cout << A.getType() << std::endl;
	A.makeSound();

	std::cout << "\nAnimal B(A)" << std::endl;
	Animal	B(A);
	std::cout << B.getType() << std::endl;
	B.makeSound();

	std::cout << "\nB = def" << std::endl;
	B = def;
	std::cout << B.getType() << std::endl;
	B.makeSound();
}

void	catClassTest()
{
	std::cout << "\nCat def" << std::endl;
	Cat	def;
	std::cout << def.getType() << std::endl;
	def.makeSound();

	std::cout << "\nCat A(\"Manul\")" << std::endl;
	Cat	A("Manul");
	std::cout << A.getType() << std::endl;
	A.makeSound();

	std::cout << "\nCat B(A)" << std::endl;
	Cat	B(A);
	std::cout << B.getType() << std::endl;
	B.makeSound();

	std::cout << "\nB = def" << std::endl;
	B = def;
	std::cout << B.getType() << std::endl;
	B.makeSound();
}

void	dogClassTest()
{
	std::cout << "\nDog def" << std::endl;
	Dog	def;
	std::cout << def.getType() << std::endl;
	def.makeSound();

	std::cout << "\nDog A(\"Wolf\")" << std::endl;
	Dog	A("Wolf");
	std::cout << A.getType() << std::endl;
	A.makeSound();

	std::cout << "\nDog B(A)" << std::endl;
	Dog	B(A);
	std::cout << B.getType() << std::endl;
	B.makeSound();

	std::cout << "\nB = def" << std::endl;
	B = def;
	std::cout << B.getType() << std::endl;
	B.makeSound();
}

void	wrongAnimalClassTest()
{
	std::cout << "WrongAnimal def" << std::endl;
	WrongAnimal	def;
	std::cout << def.getType() << std::endl;
	def.makeSound();

	std::cout << "\nWrongAnimal A(\"Hyrax\")" << std::endl;
	WrongAnimal	A("Hyrax");
	std::cout << A.getType() << std::endl;
	A.makeSound();

	std::cout << "\nWrongAnimal B(A)" << std::endl;
	WrongAnimal	B(A);
	std::cout << B.getType() << std::endl;
	B.makeSound();

	std::cout << "\nB = def" << std::endl;
	B = def;
	std::cout << B.getType() << std::endl;
	B.makeSound();
}

void	wrongCatClassTest()
{
	std::cout << "\nWrongCat def" << std::endl;
	WrongCat	def;
	std::cout << def.getType() << std::endl;
	def.makeSound();
	std::cout << CYAN << "Since def is a WrongCat object instead of a pointer or a reference to the base class, it is able to use the makeSound() function of the Wrongcat class instead of the WrongAnimal one." << DEFAULT << std::endl;

	std::cout << "\nWrongCat A(\"Manul\")" << std::endl;
	WrongCat	A("Manul");
	std::cout << A.getType() << std::endl;
	A.makeSound();

	std::cout << "\nWrongCat B(A)" << std::endl;
	WrongCat	B(A);
	std::cout << B.getType() << std::endl;
	B.makeSound();

	std::cout << "\nB = def" << std::endl;
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
