/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 08:53:06 by christophed       #+#    #+#             */
/*   Updated: 2025/05/12 08:32:31 by chdonnat         ###   ########.fr       */
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
		
		bool	operator>( const Fixed& other ) const ;
		bool	operator>=( const Fixed& other ) const ;
		bool	operator<( const Fixed& other ) const ;
		bool	operator<=( const Fixed& other ) const ;
		bool	operator==( const Fixed& other ) const ;
		bool	operator!=( const Fixed& other ) const ;
		Fixed	operator+( const Fixed& other ) const ;
		Fixed	operator-( const Fixed& other ) const ;
		Fixed	operator*( const Fixed& other ) const ;
		Fixed	operator/( const Fixed& other ) const ;
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed&		min( Fixed& f1, Fixed& f2 );
		static const Fixed&	min( const Fixed& f1, const Fixed& f2 );
		static Fixed&		max( Fixed& f1, Fixed& f2 );
		static const Fixed&	max( const Fixed& f1, const Fixed& f2 );

	private:

		const static int	_fract;
		int					_value;

};

std::ostream&	operator<<( std::ostream& os, const Fixed& fixed );

#endif
