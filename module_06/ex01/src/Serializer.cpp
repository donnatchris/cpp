/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 07:57:49 by christophed       #+#    #+#             */
/*   Updated: 2025/05/19 08:11:22 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include <string>

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

Serializer::Serializer()
{}

/* ******************************* destructor ****************************** */

Serializer::~Serializer()
{}

/* ***************************** copy constructor *************************** */

Serializer::Serializer( const Serializer& other )
{
	(void)other;
}

/* ********************** copy assignment operator ************************** */

Serializer& Serializer::operator=( const Serializer& other )
{
	(void)other;
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
