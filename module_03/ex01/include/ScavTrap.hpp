/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:24:55 by christophed       #+#    #+#             */
/*   Updated: 2025/05/04 23:21:44 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAV_TRAP
# define CLAV_TRAP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

		~ScavTrap();
		ScavTrap( const ScavTrap& other );
		ScavTrap& operator=( const ScavTrap& other );
		
		ScavTrap( const std::string& name );
		
		void	attack( const std::string& target );
		void	guardGate();

	private:
	
		ScavTrap();

};

# endif
