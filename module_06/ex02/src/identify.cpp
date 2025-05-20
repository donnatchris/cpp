/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:06:41 by christophed       #+#    #+#             */
/*   Updated: 2025/05/20 09:42:24 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Object is of type A." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Object is of type B." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Object is of type C." << std::endl;
	else
		std::cout << "Object type is unknown." << std::endl;
}

void identify(Base & p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "Object is of type A." << std::endl;
		(void)a;
		return;
	} catch (...) {}

	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "Object is of type B." << std::endl;
		(void)b;
		return;
	} catch (...) {}

	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "Object is of type C." << std::endl;
		(void)c;
		return;
	} catch (...) {}

	std::cout << "Unknown type." << std::endl;
}
