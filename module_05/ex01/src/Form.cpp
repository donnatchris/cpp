/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:37:48 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/16 17:42:02 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

Form::Form():
	_name("unamed"),
	_signed(false),
	_gradeToSign(1),
	_gradeToExecute(1)
{}

/* ******************************* destructor ****************************** */

Form::~Form()
{}

/* ***************************** copy constructor *************************** */

Form::Form( const Form& other ):
	_name(other._name),
	_signed(other._signed),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

/* ********************** copy assignment operator ************************** */

Form& Form::operator=( const Form& other )
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

/* ******************************* constructors ***************************** */

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute):
	_name(name),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

/* ******************************** getters ********************************* */

const std::string&	Form::getName() const
{
	return (_name);
}

bool				Form::getSigned() const
{
	return (_signed);
}

int			Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}
int			Form::getGradeToSign() const
{
	return (_gradeToSign);
}

/* ******************************** setters ******************************** */

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

/* ******************************** exceptions ****************************** */

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form: Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form: Grade too low!";
}

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */

/* ******************************** overloads ******************************* */

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form: " << f.getName()
		<< ", grade to execute: " << f.getGradeToExecute()
		<< ", grade to sign: " << f.getGradeToSign();
	if (f.getSigned())
		os << ", is signed.";
	else
		os << ", is not signed.";
	return (os);
}
