/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 08:53:06 by christophed       #+#    #+#             */
/*   Updated: 2025/05/04 12:12:37 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:

		Fixed();
		~Fixed();
		Fixed( const Fixed& other );
		Fixed& operator=( const Fixed& other );

		Fixed( const int integer );
		Fixed( const float floating );
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:

		const static int	_fract;
		int					_value;

};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );

#endif
