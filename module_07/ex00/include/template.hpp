/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:21:24 by christophed       #+#    #+#             */
/*   Updated: 2025/05/19 10:30:37 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void	swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T	min(T a, T b)
{
	return (a < b ? a : b);
}

template<typename T>
T	max(T a, T b)
{
	return (a > b ? a : b);
}
