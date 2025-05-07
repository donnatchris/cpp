/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:02:55 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/07 11:04:07 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact() :
	_first_name(""),
	_last_name(""),
	_nick_name(""),
	_phone_number(""),
	_darkest_secret("")
{}

Contact::~Contact()
{}

std::string Contact::getFirstName() const
{
	return (_first_name);
}

std::string Contact::getLastName() const
{
	return (_last_name);
}

std::string Contact::getNickname() const
{
	return (_nick_name);
}

std::string Contact::getPhoneNumber() const
{
	return (_phone_number);
}

std::string Contact::getDarkestSecret() const
{
	return (_darkest_secret);
}

std::string	Contact::storeInfo(std::string msg)
{
	std::string	input = "";

	while (!input.length())
	{
		std::cout << "Enter the contact's " <<  msg << " : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << BLUE "EOF detected. Exiting gracefully." RESET << std::endl;
			exit (0) ;
		}
		if(!input.length())
			std::cout << RED "Error: entry canot be empty" RESET << std::endl;
	}
	return (input);
}

void    Contact::createContact()
{
	_first_name = storeInfo("first name");
	_last_name = storeInfo("last name");
	_nick_name = storeInfo("nick name");
	_phone_number = storeInfo("phone number");
	_darkest_secret = storeInfo("darkest secret");
}

void	Contact::displayContact()
{
	std::cout << std::endl;
	std::cout << "First name :\t\t" << _first_name << std::endl;
	std::cout << "Last name :\t\t" << _last_name << std::endl;
	std::cout << "Nick name :\t\t" << _nick_name << std::endl;
	std::cout << "Phone Number :\t\t" << _phone_number << std::endl;
	std::cout << "Darkest secret :\t" << _darkest_secret << std::endl;
	std::cout << std::endl;
}
