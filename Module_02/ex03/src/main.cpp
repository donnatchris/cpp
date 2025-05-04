/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:22:43 by christophed       #+#    #+#             */
/*   Updated: 2025/05/04 21:19:00 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

bool	bsp ( Point const a, Point const b, Point const c, Point const point );

void	print_result( bool result)
{
	if (result == true)
		std::cout << "The point p is INSIDE the triangle abc" << std::endl;
	else
		std::cout << "The point p is OUTSIDE the triangle abc" << std::endl;

}

int main( void )
{
	Point	a1(0, 0);
	Point	b1(10, 0);
	Point	c1(0, 10);
	Point	p1(2,2);
	print_result(bsp(a1, b1, c1, p1));

	Point	a2(0.2f, 0.2f);
	Point	b2(10.234f, 0);
	Point	c2(0, 10);
	Point	p2(4.5f, 3.234f);
	print_result(bsp(a2, b2, c2, p2));

	return (0);
}
