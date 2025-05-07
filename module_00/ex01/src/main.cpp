/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:05:21 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/07 10:45:55 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"
#include "../include/colors.hpp"

void	displayMessage()
{
	std::cout << YELLOW "Type ADD to create a new contact, ";
	std::cout << "SEARCH to see your contacts, ";
	std::cout << "or EXIT to close the programm." RESET << std::endl << std::endl;
}

int main()
{
	PhoneBook	phone_book;
	std::string	input;

	std::cout << std::endl << YELLOW "Welcome to your Phone Book !" RESET << std::endl;
	while (true)
	{
		displayMessage();
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << BLUE "EOF detected. Exiting gracefully." RESET << std::endl;
			break ;
		}
		if (input == "ADD")
			phone_book.addContactInPhoneBook();
		else if (input == "SEARCH")
			phone_book.searchContactInPhoneBook();
		else if (input == "EXIT")
			break ;
		else
			std::cout << RED "Incorrect entry. Try again." RESET << std::endl;
	}
	return (0);
}
