/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:16:49 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/20 10:32:13 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "../include/easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    try
    {
        std::cout << "Looking for number 3 in vector:" << std::endl;
        easyfind(vec, 3);
        std::cout << "Number found!" << std::endl;
        std::cout << "Looking for number 8 in vector:" << std::endl;
        easyfind(vec, 8);
        std::cout << "Number found!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    
    try
    {
        std::cout << "Looking for number 3 in list:" << std::endl;
        easyfind(vec, 3);
        std::cout << "Number found!" << std::endl;
        std::cout << "Looking for number 8 in list:" << std::endl;
        easyfind(vec, 8);
        std::cout << "Number found!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}