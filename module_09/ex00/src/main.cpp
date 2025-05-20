/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:47:36 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/20 16:19:34 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

void exit_error()
{
    std::cerr << "Error: could not open file." << std::endl;
    exit(1);
}

int main(int ac, char **av)
{
    if (ac != 2)
        exit_error();

    return (0);
}
