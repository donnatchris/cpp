/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:15:54 by christophed       #+#    #+#             */
/*   Updated: 2025/05/22 08:54:49 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>
#include <exception>
#include <sstream>
#include <stack>

class RPN
{
	private:

		std::stack<int> _stack;

		bool isValidInt(const std::string & number) const;
		void add();
		void subtract();
		void multiply();
		void divide();

	public:

		RPN();
		~RPN();
		RPN(const RPN & other);
		RPN & operator=(const RPN & other);

		RPN(const std::string & input);

		int getResult() const;

		class InvalidInputException : public std::exception
		{
			const char * what() const throw();
		};
		
};
