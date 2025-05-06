/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:38:19 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/06 18:07:08 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "../include/ICharacter.hpp"
# include "../include/AMateria.hpp"

# define INVENTORY_SIZE 4

class Character : public ICharacter
{
	public:

		Character();
		~Character();
		Character( const Character& other );
		Character& operator=( const Character& other );

		Character(std::string name);

		std::string const &	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
				
	private:

		std::string		_name;
		AMateria		*_inventory[INVENTORY_SIZE];

};

#endif
