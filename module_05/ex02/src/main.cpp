/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:47:19 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/16 13:03:02 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{
	srand(time(NULL));  // Seed for robotomy randomness

	std::cout << "==== MODULE 05 - FULL EXECUTION TEST ====\n" << std::endl;

	// Create bureaucrats
	Bureaucrat alice("Alice", 1);
	Bureaucrat bob("Bob", 70);
	Bureaucrat charlie("Charlie", 150);

	// Display bureaucrats
	std::cout << alice << std::endl;
	std::cout << bob << std::endl;
	std::cout << charlie << std::endl;

	// Create forms with target
	ShrubberyCreationForm shrubForm("Backyard", "Nice_tree");
	RobotomyRequestForm robotomyForm("Marvin", "Jasmine");
	PresidentialPardonForm pardonForm("Chirac", "Baladur");

	std::cout << "\n--- FORMS CREATED ---" << std::endl;
	std::cout << shrubForm << std::endl;
	std::cout << robotomyForm << std::endl;
	std::cout << pardonForm << std::endl;

	// Try executing before signing
	std::cout << "\n--- EXECUTE BEFORE SIGNING ---" << std::endl;
	alice.executeForm(shrubForm);
	alice.executeForm(robotomyForm);
	alice.executeForm(pardonForm);

	// Try signing forms
	std::cout << "\n--- SIGNING FORMS ---" << std::endl;
	charlie.signForm(shrubForm);     // should fail (grade too low)
	bob.signForm(robotomyForm);      // should succeed
	alice.signForm(shrubForm);       // should succeed
	alice.signForm(pardonForm);      // should succeed

	// Execute with mixed levels
	std::cout << "\n--- EXECUTE WITH VARIOUS GRADES ---" << std::endl;
	charlie.executeForm(shrubForm);   // too low
	bob.executeForm(robotomyForm);    // should work
	bob.executeForm(pardonForm);      // too low
	alice.executeForm(pardonForm);    // should work
	alice.executeForm(shrubForm);     // should work

	// Robotomy randomness test
	std::cout << "\n--- ROBOTOMY MULTIPLE EXECUTIONS ---" << std::endl;
	for (int i = 0; i < 5; ++i)
		alice.executeForm(robotomyForm);

	std::cout << "\n==== END OF TEST ====" << std::endl;

	return (0);
}
