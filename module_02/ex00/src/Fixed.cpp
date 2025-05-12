/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:24:35 by christophed       #+#    #+#             */
/*   Updated: 2025/05/12 09:01:17 by chdonnat         ###   ########.fr       */
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

Fixed::Fixed( const Fixed& other )
{
	std::cout << "Copy constructor called" << std::endl;

	*this = other;
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
