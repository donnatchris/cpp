/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:35:26 by christophed       #+#    #+#             */
/*   Updated: 2025/05/19 09:30:33 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

static Base* create_A()
{
	return (new A());
}

static Base* create_B()
{
	return (new B());
}

static Base* create_C()
{
	return (new C());
}

typedef Base* (*create)();

Base* generate(void)
{
	create tab[3] = {create_A, create_B, create_C};
	int i = rand() % 3;
	return (tab[i]());
}
