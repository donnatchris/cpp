/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:25:10 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/20 17:01:57 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

BitcoinExchange::BitcoinExchange()
{}

/* ******************************* destructor ****************************** */

BitcoinExchange::~BitcoinExchange()
{}

/* ***************************** copy constructor *************************** */

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) :
	_data(other._data),
	_input(other._input)
{}

/* ********************** copy assignment operator ************************** */

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& other )
{
	if (this != &other)
	{
		this->_data = other._data;
		this->_input = other._input;
	}
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

/* ******************************* constructors ***************************** */

BitcoinExchange::BitcoinExchange(std::string path)
{
	std::ifstream csvFile("data.csv");
	if (!csvFile)
		throw CsvErrorException();
		
	std::string line;
	while(std::getline(csvFile, line)) {
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			throw CsvErrorException();
		std::string key = line.substr(0, pos);
		std::string value = line.substr(pos + 1);
		_data[key] = std::strtof(value.c_str(), 0);
	}
	// not finished
}

/* ******************************** getters ********************************* */

/* ******************************** setters ********************************* */

/* ************************* other public methods *************************** */

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

/* ************************************************************************** */
/*							non-member functions  							  */
/* ************************************************************************** */

/* ******************************** exceptions ****************************** */

/* ******************************** overloads ******************************* */

/* *********************** other non-member functions *********************** */

