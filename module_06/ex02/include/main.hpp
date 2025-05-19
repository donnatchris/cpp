/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:22:42 by christophed       #+#    #+#             */
/*   Updated: 2025/05/19 09:31:52 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
# include <iostream>
# include <ctime>
# include "../include/Base.hpp"
# include "../include/A.hpp"
# include "../include/B.hpp"
# include "../include/C.hpp"

Base* generate(void);
void identify(Base *p);
void identify(Base & p);

#endif