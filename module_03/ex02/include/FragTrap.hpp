/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:24:55 by christophed       #+#    #+#             */
/*   Updated: 2025/05/04 23:21:44 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:

		~FragTrap();
		FragTrap( const FragTrap& other );
		FragTrap& operator=( const FragTrap& other );
		
		FragTrap( const std::string& name );
		
		void	attack( const std::string& target );
		void	highFivesGuys(void);

	private:
	
		FragTrap();

};

# endif
