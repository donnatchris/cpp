/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:16:35 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/16 08:37:13 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "../include/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:

		Form();
		~Form();
		Form( const Form& other );
		Form& operator=( const Form& other );

		Form(const std::string& name, int gradeToSign, int gradeToExecute);

		const std::string&	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		
		void				beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
	private:

		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
