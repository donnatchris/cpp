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
#include "../include/ScavTrap.hpp"

int	main( void )
{
	ScavTrap	nono("Nono");

	nono.attack("Hades");
	nono.beRepaired(10);
	nono.guardGate();
	nono.takeDamage(200);

	return (0);
}
