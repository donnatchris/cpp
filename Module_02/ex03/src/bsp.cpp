/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:52:13 by christophed       #+#    #+#             */
/*   Updated: 2025/05/04 21:02:26 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

static Fixed	signed_area( const Point& s1, const Point& s2, const Point& s3 )
{
	return 	(s1.getFixedX() - s3.getFixedX()) *
			(s2.getFixedY() - s3.getFixedY()) -
			(s2.getFixedX() - s3.getFixedX()) *
			(s1.getFixedY() - s3.getFixedY());
}

bool	bsp ( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	area1, area2, area3;
	
	area1 = signed_area(point, a, b);
	area2 = signed_area(point, b, c);
	area3 = signed_area(point, c, a);

	if (area1 > 0 && area2 > 0 && area3 > 0)
		return (true);
	else if (area1 < 0 && area2 < 0 && area3 < 0)
		return (true);
	return (false);
}
