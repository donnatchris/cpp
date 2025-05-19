/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:46:53 by christophed       #+#    #+#             */
/*   Updated: 2025/05/19 08:02:38 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "structure_Data.hpp"

class Serializer
{
	private:

		Serializer();
		~Serializer();
		Serializer( const Serializer& other );
		Serializer& operator=( const Serializer& other );

	public:

		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif
