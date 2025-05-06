/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:09:00 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/06 18:02:08 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;
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
