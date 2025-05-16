/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:16:35 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/16 12:54:16 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTILAPARDONFORM
# define PRESIDENTILAPARDONFORM

# include <string>
# include <iostream>
# include <exception>
# include <fstream>
# include "../include/AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:

		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm( const PresidentialPardonForm& other );
		PresidentialPardonForm& operator=( const PresidentialPardonForm& other );

		PresidentialPardonForm(const std::string& name, const std::string& target);

		void	execute(Bureaucrat const & executor) const;

	private:

		std::string	_target;
};

#endif
