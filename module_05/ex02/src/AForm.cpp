/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:37:48 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/16 11:37:32 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

AForm::AForm():
	_name("unamed"),
	_signed(false),
	_gradeToSign(1),
	_gradeToExecute(1)
{}

/* ******************************* destructor ****************************** */

AForm::~AForm()
{}

/* ***************************** copy constructor *************************** */

AForm::AForm( const AForm& other ):
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

AForm& AForm::operator=( const AForm& other )
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

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute):
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

const std::string&	AForm::getName() const
{
	return (_name);
}

bool				AForm::getSigned() const
{
	return (_signed);
}

int			AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}
int			AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

/* ******************************** setters ******************************** */

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

/* ******************************** exceptions ****************************** */

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm: Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm: Grade too low!";
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("Form not signed!");
}

/* ************************* other public methods ************************** */

void	AForm::testExecution(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */

/* ******************************** overloads ******************************* */

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm: " << f.getName()
		<< ", grade to execute: " << f.getGradeToExecute()
		<< ", grade to sign: " << f.getGradeToSign();
	if (f.getSigned())
		os << ", is signed.";
	else
		os << ", is not signed.";
	return (os);
}

/* *********************** other non-member functions *********************** */

