/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:13:35 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/06 11:45:20 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "../include/AAnimal.hpp"
# include "../include/Brain.hpp"

class Cat : public AAnimal
{
	public:

		Cat();
		~Cat();
		Cat( const Cat& other );
		Cat& operator=( const Cat& other );

		Cat( const std::string& type );

		void	makeSound() const;
		Brain	*getBrain() const;

	private:

		Brain	*_brain;

};

#endif
