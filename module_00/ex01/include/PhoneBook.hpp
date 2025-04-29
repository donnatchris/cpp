/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:02:58 by chdonnat          #+#    #+#             */
/*   Updated: 2025/04/29 16:06:55 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include "Contact.hpp"

class PhoneBook {
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