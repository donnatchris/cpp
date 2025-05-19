/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:46:28 by christophed       #+#    #+#             */
/*   Updated: 2025/05/19 10:56:59 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/iter.hpp"

int main()
{
	int number_array[5] = {1, 2, 3, 4, 5};
	std::string string_array[5] = {
		"Hello",
		"World",
		"How are you?",
		"What time is it?",
		"Which world is it?"};

	std::cout << "displaying array of int:" << std::endl;
	iter(number_array, 5, display);
	std::cout << "displaying array of string:" << std::endl;
	iter(string_array, 5, display);

	return (0);
}
