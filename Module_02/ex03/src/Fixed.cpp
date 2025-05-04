/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:24:35 by christophed       #+#    #+#             */
/*   Updated: 2025/05/04 15:58:01 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/Fixed.hpp"

const int	Fixed::_fract = 8;

Fixed&	Fixed::min( Fixed& f1, Fixed& f2 )
{
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed&	Fixed::min( const Fixed& f1, const Fixed& f2 )
{
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed&	Fixed::max( Fixed& f1, Fixed& f2 )
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max( const Fixed& f1, const Fixed& f2 )
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	return (f2);
}

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

Fixed::Fixed() :
	_value(0)
{}

/* ***************************** copy constructor *************************** */

Fixed::Fixed( const Fixed& other ) :
	_value(other._value)
{}

/* ******************************* destructor ****************************** */

Fixed::~Fixed()
{}

/* ********************** copy assignment operator ************************** */

Fixed& Fixed::operator=( const Fixed& other )
{
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
	_value = integer << _fract;
}

Fixed::Fixed ( const float floating )
{
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
	_value = raw;
}

/* ************************* other public methods ************************** */

float	Fixed::toFloat( void ) const
{
	float	result;

	result = static_cast<float>(_value) / static_cast<float>(1 << _fract);
	return (result);
}

int		Fixed::toInt( void ) const
{
	int	result;

	result = _value / (1 << _fract);
	return (result);
}

bool	Fixed::operator>( const Fixed& other ) const
{
	return (this->_value > other._value);
}

bool	Fixed::operator>=( const Fixed& other ) const
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<( const Fixed& other ) const
{
	return (this->_value < other._value);
}

bool	Fixed::operator<=( const Fixed& other ) const
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==( const Fixed& other ) const
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=( const Fixed& other ) const
{
	return (this->_value != other._value);
}

Fixed	Fixed::operator+( const Fixed& other ) const
{
	Fixed	result;

	result.setRawBits(this->_value + other._value);
	return (result);
}

Fixed	Fixed::operator-( const Fixed& other ) const
{
	Fixed	result;

	result.setRawBits(this->_value - other._value);
	return (result);
}

Fixed	Fixed::operator*( const Fixed& other ) const
{
	Fixed	result;

	result.setRawBits((this->_value * other._value) >> _fract);
	return (result);
}

Fixed	Fixed::operator/( const Fixed& other ) const
{
	Fixed	result;

	if (other._value == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		result.setRawBits(0);
		return (result);
	}
	result.setRawBits((this->_value << _fract) / other._value);
	return (result);
}

Fixed&	Fixed::operator++()
{
	this->_value += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;

	_value += 1;
	return (temp);
}

Fixed&	Fixed::operator--()
{
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;

	_value -= 1;
	return (temp);
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
