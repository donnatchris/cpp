/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:25:08 by christophed       #+#    #+#             */
/*   Updated: 2025/05/05 00:05:29 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/FragTrap.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

FragTrap::FragTrap()
{
	_name = "Unamed";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "A new FragTrap has been born, but wasn't named.\n"
		<< "His name has been set to: Unamed." << std::endl;
}

/* ******************************* destructor ****************************** */

FragTrap::~FragTrap()
{
	std::cout << "FragTrap object named " << _name
		<< " has been destroyed." << std::endl;
}

/* ***************************** copy constructor *************************** */

FragTrap::FragTrap( const FragTrap& other ) :
	ClapTrap(other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "FragTrap " << _name
		<< " has just been born and is a copy of "
		<< other.getName() << "!" << std::endl;
}

/* ********************** copy assignment operator ************************** */

FragTrap& FragTrap::operator=( const FragTrap& other )
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

FragTrap::FragTrap( const std::string& name ) :
	ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "Here comes a new challenger: "
		<< "FragTrap " << _name << "!" << std::endl;
}

/* ******************************** getters ********************************* */

/* ******************************** setters ******************************** */

/* ************************* other public methods ************************** */

void	FragTrap::attack( const std::string& target )
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name
			<< " is destroyed and cannot attack." << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name
			<< " is too exhausted to attack." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name
		<< " attacks " << target
		<< " causing " << _attackDamage << " points of damages!"
		<< std::endl;
	_energyPoints--;
	displayStatus();
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name
		<< " says : High Five man !" << std::endl;
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */
