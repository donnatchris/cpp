/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:26:48 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/02 11:40:07 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

int main( void )
{
	std::cout << "Creating 2 zombies by object creation:" << std::endl;
	Zombie	stack_z1("Hades");
	Zombie	stack_z2("Poseidon");
	std::cout << std::endl;
	
	std::cout << "Creating 2 zombies with randomChump function:" << std::endl;
	randomChump("Michel");
	randomChump("Robert");
	std::cout << std::endl;

	std::cout << "Creating 5 zombies with newZombie:" << std::endl;
	const char	*heap_names[5] = { "Virginie", "Sophie", "Melanie", "Sandrine", "Lola" };	
	Zombie	*heap_z[5];
	for (int i = 0; i < 5; i++)
		heap_z[i] = newZombie(heap_names[i]);
	std::cout << std::endl;

	std::cout << "All zombies have been created" << std::endl;
	std::cout << std::endl;
	
	std::cout << "Now deleting heap zombies" << std::endl;
	for (int i = 0; i < 5; i++)
		delete heap_z[i];
	std::cout << std::endl;

	std::cout << "Now closing the programm" << std::endl;
	
	return (0);
}
