/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:44:15 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/20 14:40:55 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <exception>
# include <algorithm>

class Span
{
	public:

		Span();
		~Span();
		Span(const Span & other);
		Span & operator=(const Span & other);

		Span(unsigned int max);

		void	addNumber(int n);
		int		shortestSpan() const;
		int		longestSpan() const;

		template<typename InputIterator>
		void addNumber(InputIterator begin, InputIterator end);
		
		class TooManyElementsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NotEnoughElementsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:

		unsigned int		_max;
		std::vector<int>	_vec;

};

template<typename InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end)
{
	size_t distance = std::distance(begin, end);
	
	if (_vec.size() + distance > _max)
		throw Span::TooManyElementsException();
		
	_vec.insert(_vec.end(), begin, end);
}

#endif
