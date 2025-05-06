/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:13:35 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/06 11:35:07 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include "../include/Brain.hpp"

class AAnimal
{
	public:

		AAnimal();
		virtual ~AAnimal();
		AAnimal( const AAnimal& other );
		AAnimal& operator=( const AAnimal& other );

		AAnimal( const std::string& type );

		const std::string&	getType() const;
		virtual void		makeSound() const = 0;

	protected:

		std::string	_type;
};

#endif
