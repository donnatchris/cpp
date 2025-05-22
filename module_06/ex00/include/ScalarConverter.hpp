/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:37:18 by christophed       #+#    #+#             */
/*   Updated: 2025/05/22 11:34:49 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <cstdlib>
# include <iostream>
# include <limits>
# include <iomanip>
# include <cmath>

class ScalarConverter
{
	public:

		static void convert(std::string & literal);

	private:

		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter & other);
		ScalarConverter & operator=(const ScalarConverter & other);

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

};

#endif