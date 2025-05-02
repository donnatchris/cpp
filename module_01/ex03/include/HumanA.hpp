/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:39:41 by christophed       #+#    #+#             */
/*   Updated: 2025/05/02 20:22:10 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "../include/Weapon.hpp"

class HumanA
{
	public:

		HumanA( const std::string& name,  Weapon& weapon);
		~HumanA();

		void	attack();

	private:

		std::string	_name;
		Weapon&		_weapon;

};

#endif
