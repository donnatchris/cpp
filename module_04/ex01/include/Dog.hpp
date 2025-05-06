/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:13:35 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/06 10:47:56 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "../include/Animal.hpp"
# include "../include/Brain.hpp"

class Dog : public Animal
{
	public:

		Dog();
		~Dog();
		Dog( const Dog& other );
		Dog& operator=( const Dog& other );

		Dog( const std::string& type );

		void	makeSound() const;
		Brain	*getBrain() const;

	private:

		Brain	*_brain;

};

#endif
