/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:52:30 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/05 16:49:49 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/WrongAnimal.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

WrongAnimal::WrongAnimal() :
	_type("Unknown animal")
{}

/* ******************************* destructor ****************************** */

WrongAnimal::~WrongAnimal()
{}

/* ***************************** copy constructor *************************** */

WrongAnimal::WrongAnimal( const WrongAnimal& other ) :
	_type(other._type)
{}

/* ********************** copy assignment operator ************************** */

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other )
{
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

/* ******************************* constructors ***************************** */

WrongAnimal::WrongAnimal( const std::string& type ) :
	_type(type)
{}

/* ******************************** getters ********************************* */

const std::string&	WrongAnimal::getType() const
{
	return (_type);
}

/* ******************************** setters ******************************** */

/* ************************* other public methods ************************** */

void	WrongAnimal::makeSound() const
{
	std::cout << "Grrrrrrrrrrrrrrrrrrrrrrrrrrrraaaaaawwwwwww!" << std::endl;
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */
