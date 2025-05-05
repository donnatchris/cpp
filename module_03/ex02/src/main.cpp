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

int	main( void )
{
	FragTrap	gpt("GPT");

	gpt.attack("DeepSeek");
	gpt.beRepaired(10);
	gpt.highFivesGuys();
	gpt.takeDamage(200);

	return (0);
}
