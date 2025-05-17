/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:37:18 by christophed       #+#    #+#             */
/*   Updated: 2025/05/17 17:41:10 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <cmath>

class ScalarConverter
{
	public:

		static void convert(std::string & literal);

		static bool isChar(std::string & literal);
		static bool isInt(std::string & literal);
		static bool isFloat(std::string & literal);
		static bool isDouble(std::string & literal);

		static bool isInIntRange(std::string & literal);
		static bool isFloatInRange(std::string & literal);
		static void printNan();
		static void printInf();
		static void printNegInf();

		static void fromChar(char c);
		static void fromInt(int i);
		static void fromFloat(float f);
		static void fromDouble(double d);

	private:

		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter & other);
		ScalarConverter & operator=(const ScalarConverter & other);

};

#endif