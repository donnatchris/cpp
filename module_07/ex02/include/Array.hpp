/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:05:15 by christophed       #+#    #+#             */
/*   Updated: 2025/05/26 21:02:04 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <iostream>

template<typename T>
class Array
{
	public:

		Array() :
			_size(0),
			_ptr(NULL)
		{}

		~Array()
		{
			delete[] _ptr;
		}

		Array(const Array & other) :
			_size(other._size)
		{
			if (_size == 0)
				_ptr = NULL;
			else {
				_ptr = new T[_size];
				for (unsigned int i = 0; i < _size; i++) {
					_ptr[i] = other._ptr[i];
				}
			}
		}

		Array & operator=(const Array & other)
		{
			if (this != &other) {
				if (this->_ptr) {
					delete[] this->_ptr;
				}
				this->_size = other._size;
				if (other._size == 0)
					this->_ptr = NULL;
				else {
					this->_ptr = new T[_size];
					for (unsigned int i = 0; i < this->_size; i++) {
						this->_ptr[i] = other._ptr[i];
					}
				}
			}
			return (*this);
		}

		Array(unsigned int n) :
			_size(n)
		{
			if (_size == 0)
				_ptr = NULL;
			else {
				_ptr = new T[_size];
			}
			for (unsigned int i = 0; i < _size; i++)
				_ptr[i] = T();
		}

		unsigned int size() const
		{
			return (_size);
		}

		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw (OutOfRangeException());
			return (_ptr[index]);
		}

		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw (OutOfRangeException());
			return (_ptr[index]);
		}

		class OutOfRangeException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("Error: out of range");
			}
		};

	private:

		unsigned int	_size;
		T				*_ptr;
		
};

# endif
