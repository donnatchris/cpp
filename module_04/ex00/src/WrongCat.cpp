/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:52:30 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/05 16:50:23 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/WrongCat.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

WrongCat::WrongCat() :
	WrongAnimal("WrongCat")
{}

/* ******************************* destructor ****************************** */

WrongCat::~WrongCat()
{}

/* ***************************** copy constructor *************************** */

WrongCat::WrongCat( const WrongCat& other ) :
	WrongAnimal(other)
{
	_type = other._type;
}

/* ********************** copy assignment operator ************************** */

WrongCat& WrongCat::operator=( const WrongCat& other )
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

WrongCat::WrongCat( const std::string& type ) :
	WrongAnimal(type)
{}

/* ******************************** getters ********************************* */

/* ******************************** setters ******************************** */

/* ************************* other public methods ************************** */

void	WrongCat::makeSound() const
{
	std::cout << "Miaou! Miaou!" << std::endl;
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */
