/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:06:12 by christophed       #+#    #+#             */
/*   Updated: 2025/05/19 08:08:35 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# include "../include/structure_Data.hpp"
# include "../include/Serializer.hpp"

int main()
{
	Data original;
	original.name = "Jean Dupont";
	original.age = 42;

	// display original pointer address
	std::cout << "Original pointer : " << &original << std::endl;
	std::cout << "Original values  : name = " << original.name << ", age = " << original.age << std::endl;

	// Serialize
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized (raw) : " << raw << std::endl;

	// Deserialize
	Data* recovered = Serializer::deserialize(raw);
	std::cout << "Recovered pointer: " << recovered << std::endl;
	std::cout << "Recovered values : name = " << recovered->name << ", age = " << recovered->age << std::endl;

	// Verification
	if (recovered == &original)
		std::cout << "Success: pointers match!" << std::endl;
	else
		std::cout << "Error: pointers do not match!" << std::endl;

	return (0);
}
