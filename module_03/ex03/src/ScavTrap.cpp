/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:25:08 by christophed       #+#    #+#             */
/*   Updated: 2025/05/05 00:05:29 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/ScavTrap.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

ScavTrap::ScavTrap()
{
	_name = "Unamed";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "A new ScavTrap has been born, but wasn't named.\n"
		<< "His name has been set to: Unamed." << std::endl;
}

/* ******************************* destructor ****************************** */

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap object named " << _name
		<< " has been destroyed." << std::endl;
}

/* ***************************** copy constructor *************************** */

ScavTrap::ScavTrap( const ScavTrap& other ) :
	ClapTrap(other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ScavTrap " << _name
		<< " has just been born and is a copy of "
		<< other.getName() << "!" << std::endl;
}

/* ********************** copy assignment operator ************************** */

ScavTrap& ScavTrap::operator=( const ScavTrap& other )
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

/* ******************************* constructors ***************************** */

ScavTrap::ScavTrap( const std::string& name ) :
	ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Here comes a new challenger: "
		<< "ScavTrap " << _name << "!" << std::endl;
}

/* ******************************** getters ********************************* */

/* ******************************** setters ******************************** */

/* ************************* other public methods ************************** */

void	ScavTrap::attack( const std::string& target )
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name
			<< " is destroyed and cannot attack." << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name
			<< " is too exhausted to attack." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name
		<< " attacks " << target
		<< " causing " << _attackDamage << " points of damages!"
		<< std::endl;
	_energyPoints--;
	displayStatus();
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name
		<< " is now in Gate keeper mode." << std::endl;
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */
