/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:47:19 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/16 09:30:15 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main()
{
	std::cout << "--- Creation of a valid Bureaucrat ---" << std::endl;
	Bureaucrat b1("Jean-Michel", 42);
	std::cout << b1 << std::endl;

	std::cout << "\n--- Creation of valid Form---" << std::endl;
	Form f1("Tax number 214574", 45, 30);
	std::cout << f1 << std::endl;

	std::cout << "\n--- Signature by Bureaucrat (valid) ---" << std::endl;
	b1.signForm(f1);
	std::cout << f1 << std::endl;

	std::cout << "\n--- Creation of an invalid Bureaucrat (grade 0) ---" << std::endl;
	try {
		Bureaucrat b2("Error", 0);
	} catch (const std::exception& e) {
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}

	std::cout << "\n--- Creation of an invalid Bureaucrat (grade 151) ---" << std::endl;
	try {
		Form f2("TopSecret", 151, 10);
	} catch (const std::exception& e) {
		std::cerr << "Exception caught : " << e.what() << std::endl;
	}

	std::cout << "\n--- Signature by Bureaucrat (invalid grade) ---" << std::endl;
	Form f3("Attestation Covid", 40, 20);
	std::cout << f3 << std::endl;
	b1.signForm(f3);
	std::cout << f3 << std::endl;

	return 0;
}
