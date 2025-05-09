/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:13:35 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/09 10:04:24 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include "../include/Brain.hpp"

class Animal
{
	public:

		Animal();
		virtual ~Animal();
		Animal( const Animal& other );
		Animal& operator=( const Animal& other );

		Animal( const std::string& type );

		const std::string&	getType() const;
		virtual void		makeSound() const;

	protected:

		std::string	_type;
};

#endif
