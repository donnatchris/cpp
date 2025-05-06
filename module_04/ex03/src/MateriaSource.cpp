/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:37:37 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/06 17:10:44 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/MateriaSource.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

MateriaSource::MateriaSource()
{
	for (int i = 0; i < CONTAINER_SIZE; i++)
		_container[i] = NULL;
}

/* ******************************* destructor ****************************** */

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < CONTAINER_SIZE; i++)
	{
		if (_container[i])
		{
			delete _container[i];
			_container[i] = NULL;
		}
	}
}

/* ***************************** copy constructor *************************** */

MateriaSource::MateriaSource( const MateriaSource& other )
{
	for (int i = 0; i < CONTAINER_SIZE; i++)
	{
		_container[i] = NULL;
		if (other._container[i])
			_container[i] = other._container[i]->clone();
	}

}

/* ********************** copy assignment operator ************************** */

MateriaSource& MateriaSource::operator=( const MateriaSource& other )
{
	if (this != &other)
	{
		for (int i = 0; i < CONTAINER_SIZE; i++)
		{
			if (_container[i])
				delete _container[i];
			_container[i] = NULL;
			if (other._container[i])
				_container[i] = other._container[i]->clone();
		}
	}
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;

	for (int i = 0; i < CONTAINER_SIZE; i++)
	{
		if (!_container[i])
		{
			_container[i] = m->clone();
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < CONTAINER_SIZE; i++)
	{
		if (_container[i] && _container[i]->getType() == type)
			return (_container[i]->clone());
	}
	return (NULL);
}

/* ******************************* constructors ***************************** */

/* ******************************** getters ********************************* */

/* ******************************** setters ******************************** */

/* ************************* other public methods ************************** */

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */
