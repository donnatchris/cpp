/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:31:30 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/06 17:00:40 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "../include/IMateriaSource.hpp"

# define CONTAINER_SIZE 4

class MateriaSource : public IMateriaSource
{
	public:

		MateriaSource();
		~MateriaSource();
		MateriaSource( const MateriaSource& other );
		MateriaSource& operator=( const MateriaSource& other );

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);

	private:

		AMateria	*_container[CONTAINER_SIZE];

};

#endif
