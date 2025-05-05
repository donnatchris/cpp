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
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap	jarvis("Jarvis");

	jarvis.whoAmI();
	jarvis.attack("The doctor");
	jarvis.beRepaired(10);
	jarvis.takeDamage(200);
	jarvis.attack("The doctor");

	return (0);
}
