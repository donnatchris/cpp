/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:24:55 by christophed       #+#    #+#             */
/*   Updated: 2025/05/04 23:21:44 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONTRAP_HPP
# define DIAMONTRAP_HPP

# include <string>
# include "../include/ClapTrap.hpp"
# include "../include/FragTrap.hpp"
# include "../include/ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:

		DiamondTrap();
		~DiamondTrap();
		DiamondTrap( const DiamondTrap& other );
		DiamondTrap& operator=( const DiamondTrap& other );
		
		DiamondTrap( const std::string& name );
		
		void	attack( const std::string& target );
		void	whoAmI();

	private:

		std::string	_name;

};

# endif
