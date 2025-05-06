/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 08:22:34 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/06 10:15:18 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
	public:

		Brain();
		~Brain();
		Brain( const Brain& other );
		Brain& operator=( const Brain& other );

		std::string	getBrainIdea(const unsigned int i) const;

	protected:

		std::string	_ideas[100];

	private:


};

#endif
