/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:13:50 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/22 15:40:00 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <sstream>
#include <iostream>
#include <vector>
#include <limits>
#include <cstring>
#include <cstdlib>
#include <deque>

class PmergeMe
{
	private:

		std::vector<int>	_vector;
		std::deque<int>		_deque;
		double				_vectorTime;
		double				_dequeTime;

		void parseInput(char **argv);
		bool isValidPositiveInt(char *arg);
		void sortVector(std::vector<int> vector);
		void sortDeque(std::deque<int> deque);

	public:

		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe & other);
		PmergeMe & operator=(const PmergeMe & other);

		PmergeMe(char **argv);
		
		void displayVector();
		void displayDeque();
		void sort();

	class InvalidInputException : public std::exception
	{
		virtual const char * what() const throw();
	};

};
