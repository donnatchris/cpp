/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:52:30 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/05 16:14:41 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/Dog.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

Dog::Dog() :
	AAnimal("Dog")
{
	_brain = new Brain();
}

/* ******************************* destructor ****************************** */

Dog::~Dog()
{
	std::cout << "Dog destructor." << std::endl;
	delete _brain;
}

/* ***************************** copy constructor *************************** */

Dog::Dog( const Dog& other ) :
	AAnimal(other)
{
	_type = other._type;
}

/* ********************** copy assignment operator ************************** */

Dog& Dog::operator=( const Dog& other )
{
	if (this != &other)
	{
		AAnimal::operator=(other); 
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

/* ******************************* constructors ***************************** */

Dog::Dog( const std::string& type ) :
	AAnimal(type)
{
	_brain = new Brain();
}

/* ******************************** getters ********************************* */

Brain	*Dog::getBrain() const
{
	return (_brain);
}

/* ******************************** setters ******************************** */

/* ************************* other public methods ************************** */

void	Dog::makeSound() const
{
	std::cout << "Wof! Wof!" << std::endl;
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */
