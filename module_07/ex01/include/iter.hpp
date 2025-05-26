/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:34:36 by christophed       #+#    #+#             */
/*   Updated: 2025/05/26 20:54:51 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void	iter(T *array, int len, void (*function)(T&))
{
	for (int i = 0; i < len; i++)
		function(array[i]);
}

template<typename T>
void	iter(const T *array, int len, void (*function)(const T&))
{
	for (int i = 0; i < len; i++)
		function(array[i]);
}

template<typename T>
void	display(T data)
{
	std::cout << data << std::endl;
}
