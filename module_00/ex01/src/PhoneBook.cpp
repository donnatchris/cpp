/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:48:43 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/09 08:32:58 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "../include/PhoneBook.hpp"
#include <limits>

PhoneBook::PhoneBook() :
	_nb_of_entry(0)
{}

PhoneBook::~PhoneBook()
{}

void    PhoneBook::addContactInPhoneBook()
{
	int 	actual_entry(_nb_of_entry % 8);
	Contact	contact;

	if (_nb_of_entry >= 8)
		_contacts[actual_entry] = contact;
	_contacts[actual_entry].createContact();
	_nb_of_entry++;
}

std::string PhoneBook::formatField(const std::string field) const
{
    if (field.length() > 10)
        return (field.substr(0, 9) + ".");
    else
        return (std::string(10 - field.length(), ' ') + field);
}

void PhoneBook::printArrayLine(const Contact contact, int index)
{
	std::cout << "| " << index << " | ";
	std::cout << formatField(contact.getFirstName()) << " | ";
	std::cout << formatField(contact.getLastName()) << " | ";
	std::cout << formatField(contact.getNickname()) << " | ";
	std::cout << formatField(contact.getPhoneNumber()) << " |" << std::endl;
}

void    PhoneBook::searchContactInPhoneBook()
{
	int	i(0);
	int	input(0);

	if (!_nb_of_entry) {
		std::cout << "The Phone Book is empty" << std::endl;
		return ;
	}
	std::cout << std::endl << "YOUR CONTACT LIST:" << std::endl;
	while (i < _nb_of_entry && i < 8) {
		printArrayLine(_contacts[i], i + 1);
		i++;
	}
	std::cout << std::endl;
	std::cout << "Enter the index of the contact you want to display :" << std::endl;
	while (input < 1 || input > 8 || input > _nb_of_entry) {
		std::cin >> input;
		if (std::cin.eof())
		{
			std::cout << BLUE "EOF detected. Exiting gracefully." RESET << std::endl;
			exit(1) ;
		}
		std::cin.clear();
    	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input < 1 || input > 8 || input > _nb_of_entry)
			std::cout << RED "Wrong index. Try again :" RESET << std::endl;
	}	
	_contacts[input - 1].displayContact();
}
