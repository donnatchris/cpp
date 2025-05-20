/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:21:12 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/20 14:48:04 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

Span::Span():
	_max(0)
{}

/* ******************************* destructor ****************************** */

Span::~Span()
{}

/* ***************************** copy constructor *************************** */

Span::Span( const Span& other ):
	_max(other._max)
{
	_vec = other._vec;
}

/* ********************** copy assignment operator ************************** */

Span& Span::operator=( const Span& other )
{
	if (this != &other)
	{
		this->_max = other._max;
		this->_vec = other._vec;
	}
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

/* ******************************* constructors ***************************** */

Span::Span(unsigned int max):
	_max(max)
{}

/* ******************************** exceptions ****************************** */

const char* Span::TooManyElementsException::what() const throw()
{
	return ("Unable to add another number: Span is full");
}

const char* Span::NotEnoughElementsException::what() const throw()
{
	return ("Unable to find distance: Not enough elements in Span");
}

/* ************************* other public methods *************************** */

void	Span::addNumber(int n)
{
	if (_vec.size() == _max)
		throw Span::TooManyElementsException();
	_vec.push_back(n);
}

int		Span::shortestSpan() const
{
	if (_vec.size() < 2)
		throw NotEnoughElementsException();

	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());

	int	shortest = std::abs(tmp[0] - tmp[1]);
	int	diff;
	
	for (size_t i = 1; i < (tmp.size() - 1); i++) {
		diff = std::abs(tmp[i] - tmp[i + 1]);
		if (diff < shortest)
			shortest = diff;
	}

	return (shortest);
}

int		Span::longestSpan() const
{
	if (_vec.size() < 2)
		throw NotEnoughElementsException();
	std::vector<int>::const_iterator cit_min = std::min_element(_vec.begin(), _vec.end());
	std::vector<int>::const_iterator cit_max = std::max_element(_vec.begin(), _vec.end());
	return (*cit_max - *cit_min);
}
