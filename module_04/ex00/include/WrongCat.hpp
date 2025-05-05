/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:13:35 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/05 16:49:12 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <string>
# include "../include/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:

		WrongCat();
		virtual ~WrongCat();
		WrongCat( const WrongCat& other );
		WrongCat& operator=( const WrongCat& other );

		WrongCat( const std::string& type );

		void	makeSound() const;

};

#endif
