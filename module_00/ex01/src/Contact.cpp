/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:02:55 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/01 09:50:44 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact() :
	_first_name(""),
	_last_name(""),
	_nick_name(""),
	_phone_number(""),
	_darkest_secret("") {
}

Contact::~Contact() {
}

std::string Contact::getFirstName() const {
	return (_first_name);
}

std::string Contact::getLastName() const {
	return (_last_name);
}

std::string Contact::getNickname() const {
	return (_nick_name);
}

std::string Contact::getPhoneNumber() const {
	return (_phone_number);
}

std::string Contact::getDarkestSecret() const {
	return (_darkest_secret);
}

void	Contact::controlContactEntry(std::string entry) {
	if(!entry.length())
		std::cout << RED "Error: entry canot be empty" RESET << std::endl;
}

void    Contact::createContact() {
	while (!_first_name.length())
	{
		std::cout << "Enter the contact's first name : ";
		std::getline(std::cin, _first_name);
		controlContactEntry(_first_name);
	}
	while (!_last_name.length())
	{
		std::cout << "Enter the contact's last name : ";
		std::getline(std::cin, _last_name);
		controlContactEntry(_last_name);
	}
	while (!_nick_name.length())
	{
		std::cout << "Enter the contact's nick name : ";
		std::getline(std::cin, _nick_name);
		controlContactEntry(_nick_name);
	}
	while (!_phone_number.length())
	{
		std::cout << "Enter the contact's phone number : ";
		std::getline(std::cin, _phone_number);
		controlContactEntry(_phone_number);
	}
	while (!_darkest_secret.length())
	{
		std::cout << "Enter the contact's darkest secret : ";
		std::getline(std::cin, _darkest_secret);
		controlContactEntry(_darkest_secret);
	}
}

void	Contact::displayContact() {
	std::cout << std::endl;
	std::cout << "First name :\t\t" << _first_name << std::endl;
	std::cout << "Last name :\t\t" << _last_name << std::endl;
	std::cout << "Nick name :\t\t" << _nick_name << std::endl;
	std::cout << "Phone Number :\t\t" << _phone_number << std::endl;
	std::cout << "Darkest secret :\t" << _darkest_secret << std::endl;
	std::cout << std::endl;
}
