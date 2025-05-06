/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:32:37 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/06 16:04:10 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include <iostream>
# include "../include/AMateria.hpp"
# include "../include/ICharacter.hpp"

class Ice: public AMateria
{
	public:

		Ice();
		~Ice();
		Ice( const Ice& other );
		Ice& operator=( const Ice& other );

		AMateria*	clone() const;
		void		use(ICharacter& target);

};

#endif
