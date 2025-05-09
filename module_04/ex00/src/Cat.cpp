/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:52:30 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/05 16:14:41 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/Cat.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

Cat::Cat() :
	Animal("Cat")
{}

/* ******************************* destructor ****************************** */

Cat::~Cat()
{}

/* ***************************** copy constructor *************************** */

Cat::Cat( const Cat& other ) :
	Animal(other)
{
	_type = other._type;
}

/* ********************** copy assignment operator ************************** */

Cat& Cat::operator=( const Cat& other )
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

Cat::Cat( const std::string& type ) :
	Animal(type)
{}

/* ******************************** getters ********************************* */

/* ******************************** setters ******************************** */

/* ************************* other public methods ************************** */

void	Cat::makeSound() const
{
	std::cout << "Miaou! Miaou!" << std::endl;
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */
