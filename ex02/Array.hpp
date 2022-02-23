/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:33:14 by vicmarti          #+#    #+#             */
/*   Updated: 2022/02/23 19:36:57 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
	
	private:
		class IndexOutOfBoundsException : public std::exception
		{
			char const	*what(void) const throw()
			{
				return ("Bad index.");
			}
		};

		unsigned int	_size;
		T				*_content;

	public:
		Array(void)
			: _size(0), _content(new T[0])
		{}

		Array(unsigned int capacity)
			: _size(capacity), _content(new T[capacity])
		{}

		Array(Array const &array)
			: _size(array._size), _content(new T[array._size])
		{
			unsigned int const	size = this->_size;

			for (unsigned int i = 0; i < size; i++)
				this->_content[i] = T(array._content[i]);
		}

		virtual ~Array(void)
		{
			delete [] this->_content;
		}

		Array			&operator=(Array const &array)
		{
			unsigned int	size = this->_size;

			if (size != array._size)
			{
				size = array._size;
				this->_size = size;
				delete [] this->_content;
				this->_content = new T[size];
			}
			for (unsigned int i = 0; i < size; i++)
				this->_content[i] = T(array._content[i]);
			return (*this);
		}

		T				&operator[](unsigned int const pos)
			throw (IndexOutOfBoundsException)
		{
			if (pos >= this->_size)
				throw IndexOutOfBoundsException();
			return (this->_content[pos]);
		}


		T const			&operator[](unsigned int const pos) const
			throw (IndexOutOfBoundsException)
		{
			if (pos >= this->_size)
				throw IndexOutOfBoundsException();
			return (this->_content[pos]);
		}

		unsigned int	size(void) const
		{
			return (this->_size);
		}
};
#endif

