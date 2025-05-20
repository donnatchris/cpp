/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:42:43 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/20 14:41:24 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
	try {
		std::cout << "=== Basic test ===" << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::cout << "\n=== Exception: add too many ===" << std::endl;
		sp.addNumber(42); // doit lancer TooManyElementsException
	}
	catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n=== Exception: not enough elements ===" << std::endl;
		Span sp2(2);
		sp2.addNumber(1);
		std::cout << sp2.shortestSpan() << std::endl; // doit lancer NotEnoughElementsException
	}
	catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n=== Range insert ===" << std::endl;
		Span sp3(10000);
		std::vector<int> vec;

		for (int i = 0; i < 10000; ++i)
			vec.push_back(rand() % 1000000);

		sp3.addNumber(vec.begin(), vec.end());

		std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
