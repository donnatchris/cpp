/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:18 by christophed       #+#    #+#             */
/*   Updated: 2025/05/16 17:17:20 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "../include/AForm.hpp"
# include "../include/RobotomyRequestForm.hpp"
# include "../include/PresidentialPardonForm.hpp"
# include "../include/ShrubberyCreationForm.hpp"

class Intern
{
	public:
		
		AForm*	makeForm(std::string name, std::string target);

	private:

		static AForm* createRobotomy(const std::string& target);
		static AForm* createPresidential(const std::string& target);
		static AForm* createShruberry(const std::string& target);
		
};

#endif