/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:34:16 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/16 13:30:00 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("shrubbery creation form", 145, 137),
	_target("unamed")
{}

/* ******************************* destructor ****************************** */

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

/* ***************************** copy constructor *************************** */

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ):
	AForm(other),
	_target(other._target)
{}

/* ********************** copy assignment operator ************************** */

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

/* ******************************* constructors ***************************** */

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm("shrubbery creation form", 145, 137),
	_target(target)
{}

/* ******************************** getters ********************************* */

/* ******************************** setters ********************************* */

/* ******************************** exceptions ****************************** */

/* ************************* other public methods *************************** */

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	testExecution(executor);
	std::string filename(_target + "_shrubbery");
	std::ofstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Could not open file");
	file	<< "      /\\\n"
			<< "     /\\*\\\n"
			<< "    /\\O\\*\\\n"
			<< "   /*/\\/\\/\\\n"
			<< "  /\\O\\/\\*\\/\\\n"
			<< " /\\*\\/\\*\\/\\/\\\n"
			<< "/\\O\\/\\/*/\\/O/\\\n"
			<< "      ||\n"
			<< "      ||\n"
			<< "      ||\n";
	file.close();
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */

/* ******************************** overloads ******************************* */

/* *********************** other non-member functions *********************** */

