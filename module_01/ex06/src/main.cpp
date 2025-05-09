/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:58:42 by christophed       #+#    #+#             */
/*   Updated: 2025/05/09 11:23:33 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>
#include "../include/Harl.hpp"

void	exit_error()
{
	std::cout << "Error: One argument is needed." << std::endl;
	exit(1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error();
	
	Harl	harl;
	harl.complain(std::string(av[1]));
	return (0);
}
