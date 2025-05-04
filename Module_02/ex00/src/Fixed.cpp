/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:24:35 by christophed       #+#    #+#             */
/*   Updated: 2025/05/04 09:58:28 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/Fixed.hpp"

const int	Fixed::_fract = 8;

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

Fixed::Fixed() :
	_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/* ***************************** copy constructor *************************** */

Fixed::Fixed( const Fixed& other ) :
	_value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

/* ******************************* destructor ****************************** */

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* ********************** copy assignment operator ************************** */

Fixed& Fixed::operator=( const Fixed& other )
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		this->_value = other._value;
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

/* ******************************** getters ********************************* */

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (_value);
}

/* ******************************** setters ******************************** */

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;

	_value = raw;
}

/* ************************* other public methods ************************** */



/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */
