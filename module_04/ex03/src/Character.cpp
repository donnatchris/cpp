/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:42:02 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/06 16:10:07 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

Character::Character() :
	_name("Unamed Character")
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
}

/* ******************************* destructor ****************************** */

Character::~Character()
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

/* ***************************** copy constructor *************************** */

Character::Character( const Character& other )
{
	_name = other._name;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

/* ********************** copy assignment operator ************************** */

Character& Character::operator=( const Character& other )
{
	if (this != &other)
	{
		_name = other._name;
		
		for (int i = 0; i < INVENTORY_SIZE; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
		}
		
		for (int i = 0; i < INVENTORY_SIZE; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

Character::Character(std::string name) :
	_name(name)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
}

/* ******************************* constructors ***************************** */

/* ******************************** getters ********************************* */

std::string const & Character::getName() const
{
	return (_name);
}

/* ******************************** setters ******************************** */

/* ************************* other public methods ************************** */

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
		return ;
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= INVENTORY_SIZE || !_inventory[idx])
		return ;
	
	std::cout << _name << " " << std::flush;
	_inventory[idx]->use(target);
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */
