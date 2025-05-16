/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:16:35 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/16 13:28:03 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include <cstdlib>
# include <ctime>
# include "../include/AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:

		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm( const RobotomyRequestForm& other );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& other );

		RobotomyRequestForm(const std::string& target);

		void	execute(Bureaucrat const & executor) const;

	private:

		std::string	_target;

};

#endif
