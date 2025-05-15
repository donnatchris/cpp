/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:47:19 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/15 15:09:52 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/Bureaucrat.hpp"

int main()
{
	try
    {
		Bureaucrat b1("Ursula", 2);
		std::cout << b1 << std::endl;

		b1.incrementGrade();
		std::cout << "After promotion : " << b1 << std::endl;

		b1.incrementGrade();
		std::cout << "This message won't be display\n";
	}
	catch (const std::exception& e)
    {
		std::cerr << "Exception caught (b1) : " << e.what() << std::endl;
	}

	std::cout << "---------------------------" << std::endl;

	try
    {
		Bureaucrat b2("Thierry Breton", 149);
		std::cout << b2 << std::endl;

		b2.decrementGrade();
		std::cout << "After retrogradation : " << b2 << std::endl;

		b2.decrementGrade();
        std::cout << "This message won't be display\n";

	}
	catch (const std::exception& e)
    {
		std::cerr << "Exception caught (b2) : " << e.what() << std::endl;
	}

	std::cout << "---------------------------" << std::endl;

	try
    {
		Bureaucrat b3("Jean Michel fonctionnaire", 160);
		std::cout << b3 << std::endl;
	}
	catch (const std::exception& e)
    {
		std::cerr << "Exception caught (b3) : " << e.what() << std::endl;
	}
}
