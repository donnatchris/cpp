/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:02:58 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/07 09:46:46 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include "Contact.hpp"

class PhoneBook

{
	public:

		PhoneBook();
		~PhoneBook();

		void		addContactInPhoneBook();
		void		searchContactInPhoneBook();

	private:

		Contact		_contacts[8];
		int			_nb_of_entry;

		void		printArrayLine(const Contact contact, int index);
		std::string	formatField(const std::string field) const;
		
};

#endif
