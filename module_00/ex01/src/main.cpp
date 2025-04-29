/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:05:21 by chdonnat          #+#    #+#             */
/*   Updated: 2025/04/29 16:44:16 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "colors.hpp"

void	welcomeMessage() {
	std::cout << YELLOW "Type ADD to create a new contact, ";
	std::cout << "SEARCH to see your contacts, ";
	std::cout << "or EXIT to close the programm." RESET << std::endl << std::endl;
}

int main() {
	PhoneBook	phone_book;
	std::string	input;

	std::cout << std::endl << YELLOW "Welcome to your Phone Book !" RESET << std::endl;
	while (true) {
		welcomeMessage();
		std::getline(std::cin, input);
		if (std::cin.eof()) {
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