/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:07:51 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/21 18:01:06 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <exception>

class BitcoinExchange
{

	private:

		std::map<std::string, float>	_data;
		
		void printError(const std::string & message) const;
		void printBadInput(const std::string & line) const;
		bool isValidAmount(const std::string & amount) const;
		bool isValidDate(const std::string str) const;
		bool isValidYear(const std::string & year) const;
		bool isValidMonth(const std::string & month) const;
		bool isValidDay(const std::string & day, const std::string & month, const std::string & year) const;

	public:

		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & other);
		BitcoinExchange & operator=(const BitcoinExchange & other);
	
		void printData() const;
		void analyse(const char *path) const;

		class CsvErrorException : public std::exception
		{
			const char *what() const throw();
		};

		class FileErrorException : public std::exception
		{
			const char *what() const throw();
		};

};
