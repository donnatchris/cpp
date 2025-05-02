/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:47:32 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/02 11:49:12 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include "../include/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie		*zombieHorde;

	zombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::stringstream	ss;
		ss << name << i;
		zombieHorde[i].setName(ss.str());
	}
	return (zombieHorde);
}
