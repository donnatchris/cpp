/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:32:37 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/06 16:23:19 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include <iostream>
# include "../include/AMateria.hpp"
# include "../include/ICharacter.hpp"

class Cure: public AMateria
{
	public:

		Cure();
		~Cure();
		Cure( const Cure& other );
		Cure& operator=( const Cure& other );

		AMateria*	clone() const;
		void		use(ICharacter& target);

};

#endif
