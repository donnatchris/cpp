/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:25:17 by christophed       #+#    #+#             */
/*   Updated: 2025/05/04 23:35:39 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/ClapTrap.hpp"

int	main( void )
{
	ClapTrap	terminator("Terminator");
	ClapTrap	chappy("Chappy");

	std::cout << "Terminator has begun a fight!" << std::endl;
	terminator.displayStatus();
	terminator.attack("Martine");
	terminator.attack("Sarah Connor");
	terminator.beRepaired(2);
	terminator.beRepaired(8);
	terminator.beRepaired(8);
	terminator.beRepaired(8);
	terminator.beRepaired(8);
	terminator.beRepaired(8);
	terminator.beRepaired(8);
	terminator.beRepaired(8);
	terminator.beRepaired(8);
	terminator.attack("José");

	std::cout << "\nHere comes a new challenger!" << std::endl;
	chappy.displayStatus();
	chappy.attack("Cthulhu");
	chappy.takeDamage(5);
	chappy.beRepaired(2);
	chappy.takeDamage(5);
	chappy.takeDamage(5);
	chappy.attack("Azathoth");
	chappy.beRepaired(10);

	return (0);
}
