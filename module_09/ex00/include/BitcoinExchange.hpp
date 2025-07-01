/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:07:51 by chdonnat          #+#    #+#             */
/*   Updated: 2025/07/01 09:11:55 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <exception>
#include <cstdlib>
#include <algorithm>

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
		std::string trim(const std::string& s) const;

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
