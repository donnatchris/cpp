/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:25:10 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/21 19:08:30 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

BitcoinExchange::BitcoinExchange()
{
	std::ifstream csvFile("data.csv");
	if (!csvFile)
		throw CsvErrorException();
		
	std::string line;

	if (!std::getline(csvFile, line))
		throw CsvErrorException();

	while(std::getline(csvFile, line)) {
		if (line.empty())
			return ;
		if (std::count(line.begin(), line.end(), ',') != 1)
			throw CsvErrorException();
		size_t pos = line.find(',');
		if (pos == 0 || pos == std::string::npos || pos == line.size() - 1)
			throw CsvErrorException();
		std::string key = line.substr(0, pos);
		std::string value = line.substr(pos + 1);
		_data[key] = std::strtof(value.c_str(), NULL);
	}
}

/* ******************************* destructor ****************************** */

BitcoinExchange::~BitcoinExchange()
{}

/* ***************************** copy constructor *************************** */

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) :
	_data(other._data)
{}

/* ********************** copy assignment operator ************************** */

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& other )
{
	if (this != &other)
	{
		this->_data = other._data;
	}
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

/* ******************************** exceptions ****************************** */

const char* BitcoinExchange::CsvErrorException::what() const throw()
{
	return ("Error: CSV file error");
}

const char* BitcoinExchange::FileErrorException::what() const throw()
{
	return ("Error: Could not open file");
}

/* ************************* other public methods *************************** */

void BitcoinExchange::printData() const
{
	for (std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); ++it)
	{
		std::cout << it->first << " => "
			<< std::fixed << std::setprecision(2)
			<< it->second << std::endl;
	}
}

void BitcoinExchange::analyse(const char *path) const
{
	std::ifstream file(path);
	if (!file)
		throw FileErrorException();
	
	std::string line;
	if (!std::getline(file, line))
		throw FileErrorException();

	while (std::getline(file, line)) {
		if (std::count(line.begin(), line.end(), '|') != 1) {
			printBadInput(line);
			continue ;
		}

		size_t separator = line.find('|');
		std::string date = trim(line.substr(0, separator));
		if (!isValidDate(date)) {
			continue ;
		}

		std::string amount = trim(line.substr(separator + 1));
		if (!isValidAmount(amount))
			continue ;
		
		std::map<std::string, float>::const_iterator cit = _data.lower_bound(date);
		if (cit == _data.end() || cit->first != date) {
			if (cit != _data.begin())
				cit--;
			else {
				printBadInput(line);
				continue ;
			}
		}
		float conversion = std::strtof(amount.c_str(), NULL) * cit->second;
		std::cout << date << " => " << amount << " = " << conversion << std::endl;
	}
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

bool BitcoinExchange::isValidYear(const std::string & year) const
{
	if (year.length() != 4)
		return (false);

	for (int i = 0; i < 4; i++) {
		if (!std::isdigit(year[i]))
			return (false);
		}
	return (true);
}

bool BitcoinExchange::isValidMonth(const std::string & month) const
{
	if (month.length() != 2)
		return (false);

	for (int i = 0; i < 2; i++) {
		if (!std::isdigit(month[i]))
			return (false);
		}
	int n = std::atoi(month.c_str());
	if (n < 1 || n > 12)
		return (false);
	return (true);
}

bool BitcoinExchange::isValidDay(const std::string & day, const std::string & month, const std::string & year) const
{
	if (day.length() != 2)
		return (false);

	for (int i = 0; i < 2; i++) {
		if (!std::isdigit(day[i]))
			return (false);
		}
	int nday = std::atoi(day.c_str());
	int nmonth = std::atoi(month.c_str());
	int nyear = std::atoi(year.c_str());
	if (nday > 31)
		return (false);
	if (nmonth == 2) {
		if (nyear % 4 == 0) {
			if (nday > 29)
				return (false);
		}
		else
			if (nday > 28)
				return (false);
	}
	if (nmonth == 2 || nmonth == 4 || nmonth == 6 || nmonth == 9 || nmonth == 11) {
		if (nday > 30)
			return (false);
	}
	return (true);
}

bool BitcoinExchange::isValidDate(const std::string str) const
{
	if (str.empty()) {
		printError("empty date.");
		return (false);
	}
	if (str.length() != 10)
		return (false);

	std::string year = str.substr(0, 4);
	std::string month = str.substr(5, 2);
	std::string day = str.substr(8, 2);

	return (isValidYear(year) && isValidMonth(month) && isValidDay(day, month, year));
}

void BitcoinExchange::printError(const std::string & message) const
{
	std::cout << "Error: " << message << std::endl;
}

void BitcoinExchange::printBadInput(const std::string & line) const
{
	std::cerr << "Error: bad input => " << line << std::endl;
}

bool BitcoinExchange::isValidAmount(const std::string & amount) const
{
	if (amount.empty()) {
		printError("empty value.");
		return (false);
	}
	float amountf = std::strtod(amount.c_str(), NULL);
	if (amountf > 1000.0f) {
		printError("too large a number.");
		return (false);
	}
	if (amountf < 0.0f) {
		printError("not a positive number.");
		return (false);
	}
	return (true);
}

std::string BitcoinExchange::trim(const std::string& s) const
{
	size_t start = 0;
	while (start < s.length() && std::isspace(s[start]))
		++start;

	size_t end = s.length();
	while (end > start && std::isspace(s[end - 1]))
		--end;

	return s.substr(start, end - start);
}
