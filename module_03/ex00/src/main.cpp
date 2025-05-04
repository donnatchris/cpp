/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:25:17 by christophed       #+#    #+#             */
/*   Updated: 2025/05/05 00:03:50 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/ClapTrap.hpp"

int	main( void )
{
	ClapTrap	terminator("Terminator");
	
	terminator.attack("Martine");
	terminator.attack("Sarah Connor");
	terminator.beRepaired(2);
	terminator.beRepaired(8);
	terminator.beRepaired(8);
	terminator.beRepaired(8);
	terminator.beRepaired(4);
	terminator.beRepaired(8);
	terminator.beRepaired(7);
	terminator.beRepaired(8);
	terminator.beRepaired(12);
	terminator.attack("José");
	
	ClapTrap	chappy("Chappy");
	
	chappy.attack("Cthulhu");
	chappy.takeDamage(5);
	chappy.beRepaired(2);
	chappy.takeDamage(5);
	chappy.takeDamage(5);
	chappy.attack("Azathoth");
	chappy.beRepaired(10);

	return (0);
}
