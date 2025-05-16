/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:33:53 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/16 17:39:23 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

PresidentialPardonForm::PresidentialPardonForm():
	AForm("presidential pardon form", 25, 5),
	_target("unamed")
{}

/* ******************************* destructor ****************************** */

PresidentialPardonForm::~PresidentialPardonForm()
{}

/* ***************************** copy constructor *************************** */

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ):
	AForm(other),
	_target(other._target)
{}

/* ********************** copy assignment operator ************************** */

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
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

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm("presidential pardon form", 25, 5),
	_target(target)
{}

/* ******************************** getters ********************************* */

/* ******************************** setters ********************************* */

/* ******************************** exceptions ****************************** */

/* ************************* other public methods *************************** */

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	testExecution(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox."<< std::endl;
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */

/* ******************************** overloads ******************************* */

/* *********************** other non-member functions *********************** */

