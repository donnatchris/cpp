/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:55:07 by christophed       #+#    #+#             */
/*   Updated: 2025/05/04 21:06:54 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "../include/Fixed.hpp"

class Point
{
	public:

		Point();
		~Point();
		Point( const Point& other );
		Point& operator=( const Point& other );

		Point( const int x, const int y );
		Point( const float x, const float y );
		Point( const int x, const float y );
		Point( const float x, const int y );

		Fixed	getFixedX() const;
		Fixed	getFixedY() const;

	private:

		Fixed const _x;
		Fixed const _y;

};

#endif
