/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:21:29 by christophed       #+#    #+#             */
/*   Updated: 2025/05/19 09:34:58 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	Base* ptr = generate();

	// test by pointer
	std::cout << "Test by pointer:" << std::endl;
	identify(ptr);

	// test by reference
	std::cout << "Test by reference:" << std::endl;
	identify(*ptr);

	delete ptr;
	return (0);
}
