/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:25:08 by christophed       #+#    #+#             */
/*   Updated: 2025/05/04 23:33:29 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/ClapTrap.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* ***************************** copy constructor *************************** */

ClapTrap::ClapTrap( const ClapTrap& other ) :
	_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{}

/* ******************************* destructor ****************************** */

ClapTrap::~ClapTrap()
{}

/* ********************** copy assignment operator ************************** */

ClapTrap& ClapTrap::operator=( const ClapTrap& other )
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

ClapTrap::ClapTrap( const std::string& name ) :
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{}

/* ******************************** getters ********************************* */

const std::string&	ClapTrap::getName() const
{
	return(_name);
}

const int&			ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}

const int&			ClapTrap::getEnergyPoints() const
{
	return (_energyPoints);
}

const int&			ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

/* ******************************** setters ******************************** */

void	ClapTrap::setAttackDamage( int damage )
{
	if (damage >= 0)
		_attackDamage = damage;
	else
		std::cerr << "Error : Cannot set attackDamage : invalid value" << std::endl;
}

/* ************************* other public methods ************************** */

void	ClapTrap::attack( const std::string& target )
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name
			<< " is destroyed and cannot attack." << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name
			<< " is too exhausted to attack." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name
		<< " attacks " << target
		<< " causing " << _attackDamage << " points of damage!"
		<< std::endl;
	_energyPoints--;
	displayStatus();
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap " << _name << " has taken "
		  << amount << " damage(s)! " << std::endl;
	_hitPoints -= amount;
	if (_hitPoints <= 0)
	{
		_hitPoints = 0;
		std::cout << _name << " has been destroyed!" << std::endl;
		return ;
	}
	displayStatus();
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name
			<< " is destroyed and cannot be repaired." << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name
			<< " is too exhausted to repair." << std::endl;
		return ;
	}
	if (amount == 0)
	{
		std::cerr << "Error: invalid repair amount." << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself and gains "
	          << amount << " hit points! " << std::endl;
	displayStatus();
}

void	ClapTrap::displayStatus() const
{
	std::cout << "ClapTrap " << _name << " has "
		<< "HP: " << _hitPoints
		<< " | EP: "<< _energyPoints
		<< " | AD: " << _attackDamage << std::endl;
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

ClapTrap::ClapTrap() :
	_name("unamed"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{}

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */
