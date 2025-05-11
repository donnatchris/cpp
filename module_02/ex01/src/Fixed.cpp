/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:24:35 by christophed       #+#    #+#             */
/*   Updated: 2025/05/11 15:56:46 by christophed      ###   ########.fr       */
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
		_value = other._value;
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

/* ******************************* constructors ***************************** */

Fixed::Fixed( const int integer )
{
	std::cout << "Int constructor called" << std::endl;

	_value = integer << _fract;
}

Fixed::Fixed ( const float floating )
{
	std::cout << "Float constructor called" << std::endl;

	_value = static_cast<int>(roundf(floating * (1 << _fract)));
}

/* ******************************** getters ********************************* */

int	Fixed::getRawBits( void ) const
{
	return (_value);
}

/* ******************************** setters ******************************** */

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;

	_value = raw;
}

/* ************************* other public methods ************************** */

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(_value) / (1 << _fract));
}

int		Fixed::toInt( void ) const
{
	return (_value >> _fract);
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */

std::ostream& operator<<( std::ostream& os, const Fixed& fixed )
{
	if ((fixed.getRawBits() & 0xFF) == 0)
		return (os << fixed.toInt());
	return (os << fixed.toFloat());
}
