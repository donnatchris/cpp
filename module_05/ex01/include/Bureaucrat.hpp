/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:15:25 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/15 16:19:17 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class	Form;

class   Bureaucrat
{
	public:

		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		Bureaucrat(const std::string& name, int grade);
		
		const std::string&	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm() const;

	private:

		const std::string 	_name;
		int					_grade;

};

class	GradeTooHighException : public std::exception
{
	public:

		virtual const char* what() const throw();
};

class	GradeTooLowException : public std::exception
{
	public:

		virtual const char* what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif