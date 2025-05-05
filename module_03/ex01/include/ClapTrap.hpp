/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:24:55 by christophed       #+#    #+#             */
/*   Updated: 2025/05/04 23:21:44 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	public:

		ClapTrap();
		virtual ~ClapTrap();
		ClapTrap( const ClapTrap& other );
		ClapTrap& operator=( const ClapTrap& other );
		
		ClapTrap( const std::string& name );
		
		virtual void	attack( const std::string& target );
		void			takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );

		const std::string&	getName() const;
		const int&			getHitPoints() const;
		const int&			getEnergyPoints() const;
		const int&			getAttackDamage() const;
		void				setAttackDamage( int damage );

		void	displayStatus() const;

	protected:
	
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

};

# endif
