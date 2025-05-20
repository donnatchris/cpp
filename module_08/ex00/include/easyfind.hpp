/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:07:04 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/20 10:16:21 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <algorithm>

template<typename T>
typename T::iterator easyfind(T & container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);

	if (it != container.end())
		return (it);
	else
		throw std::runtime_error("Value not found in container");
}

#endif