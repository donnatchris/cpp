/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:50:10 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/07 20:49:36 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

/* ******************************* constructor ****************************** */

Zombie::Zombie( std::string name) :
    _name(name)
{
    Zombie::announce();
}

/* ******************************* destructor ****************************** */

Zombie::~Zombie()
{
    std::cout << _name << " has been destroyed." << std::endl;
}

/* ******************************** getters ******************************** */

/* ******************************** setters ******************************** */

/* ************************* other public methods ************************** */

void    Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

Zombie::Zombie()
{}
/* ************************* other private methods ************************** */

