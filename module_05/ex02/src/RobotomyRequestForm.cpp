/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:51:42 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/16 12:56:11 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

RobotomyRequestForm::RobotomyRequestForm():
	AForm("unamed", 72, 45),
	_target("unamed")
{}

/* ******************************* destructor ****************************** */

RobotomyRequestForm::~RobotomyRequestForm()
{}

/* ***************************** copy constructor *************************** */

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ):
	AForm(other),
	_target(other._target)
{}

/* ********************** copy assignment operator ************************** */

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
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

RobotomyRequestForm::RobotomyRequestForm(const std::string& name, const std::string& target):
	AForm(name, 72, 45),
	_target(target)
{}

/* ******************************** getters ********************************* */

/* ******************************** setters ********************************* */

/* ******************************** exceptions ****************************** */

/* ************************* other public methods *************************** */

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	static int r = 0;
	if (!r)
	{
		r = 1;
		srand(time(NULL));
	}
	testExecution(executor);
	std::cout << "* drilling noise *" << std::endl;
	int value = rand();
	if (value % 2)
		std::cout << "The robotomy has failed." << std::endl;
	else
		std::cout << _target << " has been robotomized successfuly." << std::endl;
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */

/* ******************************** overloads ******************************* */

/* *********************** other non-member functions *********************** */

