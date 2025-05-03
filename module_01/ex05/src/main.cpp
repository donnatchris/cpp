/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:58:42 by christophed       #+#    #+#             */
/*   Updated: 2025/05/03 12:02:43 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/Harl.hpp"

int	main()
{
	Harl	harl;

	std::cout << "Calling Harl for debug :" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "Calling Harl for info :" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "Calling Harl for warning :" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "Calling Harl for error :" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "Calling Harl for invalid reason :" << std::endl;
	harl.complain("invalid");
	std::cout << std::endl;
}
