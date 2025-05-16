/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:16:35 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/16 11:34:26 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "../include/Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:

		AForm();
		virtual ~AForm();
		AForm( const AForm& other );
		AForm& operator=( const AForm& other );

		AForm(const std::string& name, int gradeToSign, int gradeToExecute);

		const std::string&	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		
		void				beSigned(const Bureaucrat& b);
		virtual void		execute(Bureaucrat const & executor) const = 0;
		void				testExecution(Bureaucrat const & executor) const;

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

		class	NotSignedException : public std::exception
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

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
