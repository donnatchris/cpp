/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:59:30 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/02 12:59:30 by chdonnat         ###   ########.fr       */
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
	return (0);
}
