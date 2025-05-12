/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 08:53:06 by christophed       #+#    #+#             */
/*   Updated: 2025/05/12 08:31:31 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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
