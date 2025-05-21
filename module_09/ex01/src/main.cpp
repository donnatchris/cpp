/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:33:18 by christophed       #+#    #+#             */
/*   Updated: 2025/05/21 23:39:40 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error: one argument needed!" << std::endl;
		return (1);
	}


	try {
		std::string input(av[1]);
		RPN rpn(input);
		std::cout << rpn.getResult() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return (0);
}