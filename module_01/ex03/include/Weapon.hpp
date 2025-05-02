/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:08:12 by christophed       #+#    #+#             */
/*   Updated: 2025/05/02 20:20:02 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	public:

		Weapon();
		Weapon( const std::string& type);
		~Weapon();

		const std::string&	getType() const;
		void				setType(const std::string& type);

	private:

		std::string	_type;

};

#endif
