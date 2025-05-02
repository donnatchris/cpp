/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:54:53 by christophed       #+#    #+#             */
/*   Updated: 2025/05/02 19:04:33 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main( void )
{
	std::string		string("HI THIS IS BRAIN");
	std::string		*stringPTR = &string;
	std::string&	stringREF = string;
	
	std::cout << "Adress of string\t\t:" << &string << std::endl;;
	std::cout << "Adress of string by pointer\t:" << stringPTR << std::endl;
	std::cout << "Adress of string by reference\t:" << &stringREF << std::endl;
	
	std::cout << "Value of string\t\t\t:" << string << std::endl;;
	std::cout << "Value of string by pointer\t:" << *stringPTR << std::endl;
	std::cout << "Value of string by reference\t:" << stringREF << std::endl;

	return (0);
}
