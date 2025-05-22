/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:03:29 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/22 15:17:37 by chdonnat         ###   ########.fr       */
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
   }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}