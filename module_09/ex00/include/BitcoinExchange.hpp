/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:07:51 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/20 16:24:44 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>


class BitcoinExchange
{

	private:

		std::map<std::string, float>	_data;
		std::map<std::string, float>	_input;
		
		BitcoinExchange();
		
	public:

		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & other);
		BitcoinExchange & operator=(const BitcoinExchange & other);
		
		BitcoinExchange(std::string filename);

};
