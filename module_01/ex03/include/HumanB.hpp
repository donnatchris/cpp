/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:39:41 by christophed       #+#    #+#             */
/*   Updated: 2025/05/02 20:25:15 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "../include/Weapon.hpp"

class HumanB
{
	public:

		HumanB( const std::string& name );
		~HumanB();

		void	attack();
		void	setWeapon( Weapon& weapon );

	private:
		
		std::string	_name;
		Weapon		*_weapon;

};

#endif
