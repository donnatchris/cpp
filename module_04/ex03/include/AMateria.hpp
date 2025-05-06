/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:09:00 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/06 16:17:11 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "../include/ICharacter.hpp"

class AMateria
{
	public:

		AMateria();
		virtual ~AMateria();
		AMateria( const AMateria& other );
		AMateria& operator=( const AMateria& other );

		AMateria(std::string const & type);

		std::string	const & getType() const;
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:

		std::string	_type;

};

#endif
