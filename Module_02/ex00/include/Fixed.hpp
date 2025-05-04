/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 08:53:06 by christophed       #+#    #+#             */
/*   Updated: 2025/05/04 09:56:50 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:

		Fixed();
		~Fixed();
		Fixed( const Fixed& other );
		Fixed& operator=( const Fixed& other );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:

		const static int	_fract;
		int					_value;

};

#endif
