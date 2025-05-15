/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:37:48 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/15 16:13:34 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

Form::Form():
	_name("unamed"),
	_gradeToSign(1),
	_gradeToExecute(1),
	_signed(false)
{}

/* ******************************* destructor ****************************** */

Form::~Form()
{}

/* ***************************** copy constructor *************************** */

Form::Form( const Form& other ):
	_name(other._name),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute),
	_signed(other._signed)
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
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(false)
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

/* ************************* other public methods ************************** */

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */

/* ******************************** exceptions ****************************** */

const char* GradeTooHighException::what() const throw()
{
	return "Form: Grade too high!";
}

const char* GradeTooLowException::what() const throw()
{
	return "Form: Grade too low!";
}

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

/* *********************** other non-member functions *********************** */

