/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:03:29 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/23 10:35:59 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "Arguments needed! (positive integers)" << std::endl;
        return (1);
    }
    try
    {
        PmergeMe pm(av);
        std::cout << "Before:  ";
        pm.displayVector();
        pm.sort();
		std::cout << "After:   ";
		pm.displayVector();

		pm.displaySortVectorDuration();
   }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}