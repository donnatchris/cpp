/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:38:02 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/06 11:46:42 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "../include/AAnimal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

void	exit_error()
{
	std::cerr << "Error : 1 arguemnt needed (number of animals)" << std::endl;
	exit(1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		exit_error();

	// AAnimal animal("Cat");

	std::string arg = av[1];
	int	size;
	std::istringstream(arg) >> size;
	
	AAnimal* animal_array[size];
	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			animal_array[i] = new Dog;
		else
			animal_array[i] = new Cat;
	}
	
	for (int i = 0; i < size; i++)
	{
		std::cout << animal_array[i]->getType() << std::endl;
		animal_array[i]->makeSound();
		if (Dog* dog = dynamic_cast<Dog*>(animal_array[i]))
			std::cout << dog->getBrain()->getBrainIdea(i) << std::endl;
		if (Cat* cat = dynamic_cast<Cat*>(animal_array[i]))
			std::cout << cat->getBrain()->getBrainIdea(i) << std::endl;
	}

	for (int i = 0; i < size; i++)
		delete animal_array[i];
	
	return 0;
}