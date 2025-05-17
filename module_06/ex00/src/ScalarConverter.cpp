/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:54:08 by christophed       #+#    #+#             */
/*   Updated: 2025/05/17 17:39:14 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

/* ************************************************************************** */
/*								canonical form  							  */
/* ************************************************************************** */

/* *************************** default constructor ************************** */

ScalarConverter::ScalarConverter()
{}

/* ******************************* destructor ****************************** */

ScalarConverter::~ScalarConverter()
{}

/* ***************************** copy constructor *************************** */

ScalarConverter::ScalarConverter( const ScalarConverter& other )
{
	(void)other;
}

/* ********************** copy assignment operator ************************** */

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other )
{
	(void)other;
	return (*this);
}

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

void ScalarConverter::convert(std::string & literal)
{
	if (ScalarConverter::isChar(literal)) {
		std::cout << "Is a char" << std::endl;
		ScalarConverter::fromChar(literal[0]);
	}
	else if (ScalarConverter::isInt(literal)) {
		std::cout << "Is an int" << std::endl;
		ScalarConverter::fromInt(std::atoi(literal.c_str()));
	}
	else if (ScalarConverter::isFloat(literal)) {
		std::cout << "Is a float" << std::endl;
		ScalarConverter::fromFloat(std::atof(literal.c_str()));
	}
	else if (ScalarConverter::isDouble(literal)) {
		std::cout << "Is a double" << std::endl;
		ScalarConverter::fromDouble(std::strtod(literal.c_str(), NULL));
	}
	else
		std::cerr << "Error: no type found!" << std::endl;
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */

bool ScalarConverter::isChar(std::string & literal)
{
	if (literal.empty())
		return (false);

	return (literal.length() == 1 && std::isprint(literal[0]) && !isdigit(literal[0]));
}

bool ScalarConverter::isInIntRange(std::string & literal)
{
	long l = std::strtol(literal.c_str(), 0, 10);
	
	return (l <= std::numeric_limits<int>::max() && l >= std::numeric_limits<int>::min());
}

bool ScalarConverter::isInt(std::string & literal)
{
	if (literal.empty())
		return (false);
	
	size_t i = 0;
	size_t len = literal.length();

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == len)
		return (false);
	for (; i < len; i++) {
		if (!std::isdigit(literal[i]))
			return (false);
	}
	if (!ScalarConverter::isInIntRange(literal))
		return (false);
	return (true);
}

bool ScalarConverter::isFloatInRange(std::string & literal)
{
	double d = std::strtod(literal.c_str(), 0);
	
	return (d <= std::numeric_limits<float>::max() && d >= -std::numeric_limits<float>::max());
}

bool ScalarConverter::isFloat(std::string & literal)
{
	if (literal.empty())
		return (false);

	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);
	
	size_t i = 0;
	size_t len = literal.length();
	size_t pointCount = 0;
	size_t digitCount = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == len)
		return (false);
	for (; i < len - 1; i++) {
		if (isdigit(literal[i]))
			digitCount++;
		else if (literal[i] == '.')
			pointCount++;
		else
			return (false);
	}
	if (literal[i] != 'f')
		return (false);
	if (!ScalarConverter::isFloatInRange(literal))
		return (false);
	return (pointCount == 1 && digitCount > 0);
}

bool ScalarConverter::isDouble(std::string & literal)
{
	if (literal.empty())
		return (false);

	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	
	size_t pointCount = 0;
	size_t i = 0;
	size_t len = literal.length();

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == len)
		return (false);
	for (; i < len; i++) {
		if (!std::isdigit(literal[i]) && literal[i] != '.')
			return (false);
		if (literal[i] == '.')
			pointCount++;
	}
	return (pointCount == 1);
}

void ScalarConverter::fromChar(char c)
{
	// char conversion
	std::cout << "char: '" << c << "'" << std::endl;

	// int conversion
	std::cout << "int: " << static_cast<int>(c) << std::endl;

	// fixing
	std::cout << std::fixed << std::setprecision(1);

	// float conversion
	std::cout << "float: " << static_cast<float>(c)  << "f" << std::endl;

	// double conversion
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::fromInt(int i)
{
	// char conversion
	if (i >= 0 && i <= 127) {
		if (std::isprint(i))
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	// int conversion
	std::cout << "int: " << i << std::endl;

	// fixing
	std::cout << std::fixed << std::setprecision(1);

	// float conversion
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;

	// double conversion
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}
void ScalarConverter::printNan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void ScalarConverter::printInf()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

void ScalarConverter::printNegInf()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: inff" << std::endl;
	std::cout << "double: inf" << std::endl;
}

void ScalarConverter::fromFloat(float f)
{
	if (std::isnan(f)) {
		ScalarConverter::printNan();
		return;
	}

	if (std::isinf(f)) {
		ScalarConverter::printInf();
		return ;
	}

	int i = static_cast<int>(f);
	bool hasFractionalPart = std::fabs(f - static_cast<float>(i)) > 0.000001f;

	// char conversion
	if (!hasFractionalPart) {
		if (i >= 0 && i <= 127) {
			if (std::isprint(i))
				std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	// int conversion
	std::cout << "int: " << static_cast<int>(f) << std::endl;

	// fixing
	std::cout << std::fixed << std::setprecision(1);

	// float conversion
	std::cout << "float: " << f << "f" << std::endl;

	// double conversion
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::fromDouble(double d)
{
	if (std::isnan(d)) {
		ScalarConverter::printNan();
		return ;
	}

	if (std::isinf(d)) {
		ScalarConverter::printInf();
		return ;
	}

	int i = static_cast<int>(d);
	bool hasFractionalPart = std::fabs(d - static_cast<double>(i)) > 0.000001f;

	// char conversion
	if (!hasFractionalPart) {
		if (i >= 0 && i <= 127) {
			if (std::isprint(i))
				std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	// int conversion
	std::cout << "int: " << static_cast<int>(d) << std::endl;

	// fixing 
	std::cout << std::fixed << std::setprecision(1);

	// float conversion
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

	// double conversion
	std::cout << "double: " << d << std::endl;
}
