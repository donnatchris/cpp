/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:53:43 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/15 16:18:54 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

Bureaucrat::Bureaucrat()
{}

/* ******************************* destructor ****************************** */

Bureaucrat::~Bureaucrat()
{}

/* ***************************** copy constructor *************************** */

Bureaucrat::Bureaucrat( const Bureaucrat& other ) :
	_name(other._name),
	_grade(other._grade)
{}

/* ********************** copy assignment operator ************************** */

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

/* ******************************* constructors ***************************** */

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	_name(name),
	_grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

/* ******************************** getters ********************************* */

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

/* ******************************** setters ******************************** */

void Bureaucrat::incrementGrade()
{
	if (--_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	if (++_grade > 150)
		throw GradeTooLowException();
}

/* ************************* other public methods ************************** */

void Bureaucrat::signForm() const
{
	try ()
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */

/* ******************************** exceptions ****************************** */

const char* GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char* GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

/* ******************************** overloads ******************************* */

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat " << b.getGrade();
	return (os);
}
