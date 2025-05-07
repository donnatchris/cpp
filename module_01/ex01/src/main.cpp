/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:59:30 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/07 20:54:28 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include "../include/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

bool    isValidInt( char *str )
{
	while (*str)
	{
		if (!std::isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

int	errorExit( void )
{
	std::cerr << "Error: you must pass 2 arguments: a positive number and a name"
		<< std::endl;
	return (1);
}

int main(int ac, char **av)
{
	if (ac != 3 || !isValidInt(av[1]))
		return (errorExit());
	
	Zombie  	*horde;
	int     	number;
	
	std::string	nb(av[1]);
	std::stringstream   ss(nb);
	ss >> number;
	if (number < 1)
		return(errorExit());

	horde = zombieHorde(number, av[2]);

	for (int i = 0; i < number; i++)
		horde[i].announce();

	delete[] horde;
	return (0);
}
