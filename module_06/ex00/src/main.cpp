/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:58:03 by christophed       #+#    #+#             */
/*   Updated: 2025/05/17 13:05:09 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "../include/ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "You must pass one argument!" << std::endl;
		return (1);
	}

	std::string arg(av[1]);
	ScalarConverter::convert(arg);
	return (0);
}
