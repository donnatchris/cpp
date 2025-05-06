/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:13:35 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/05 16:48:25 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
	public:

		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal( const WrongAnimal& other );
		WrongAnimal& operator=( const WrongAnimal& other );

		WrongAnimal( const std::string& type );

		const std::string&	getType() const;
		void		makeSound() const;

	protected:

		std::string	_type;
};

#endif
