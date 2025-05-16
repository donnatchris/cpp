/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:00:10 by christophed       #+#    #+#             */
/*   Updated: 2025/05/16 17:39:44 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"


AForm* Intern::createRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::createShruberry(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	typedef AForm* (*FormCreator)(const std::string&);

	const std::string names[3] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};

	FormCreator creators[3] = {
		Intern::createRobotomy,
		Intern::createPresidential,
		Intern::createShruberry
	};

	for (int i = 0; i < 3; i++) {
		if (name == names[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return (creators[i](target));
		}
	}

	std::cerr << "Intern couldn't find the form " << name << "." << std::endl;
	throw std::invalid_argument("Unknown form name");

}
