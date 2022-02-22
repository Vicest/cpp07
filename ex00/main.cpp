/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:28:53 by vicmarti          #+#    #+#             */
/*   Updated: 2022/02/22 21:22:00 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <string>
#include <iostream>

class Foo
{
	public:
		Foo(void)
			: _name(""), _i(0), _c(0)
		{};

		Foo(std::string const name, int const i, char const c)
			: _name(name), _i(i), _c(c)
		{};

		Foo(Foo const &foo)
			: _name(foo._name), _i(foo._i), _c(foo._c)
		{};

		Foo	&operator=(Foo const &rhs)
		{
			this->_i = rhs._i;
			this->_c = rhs._c;
			return (*this);
		}

		bool operator==(Foo const &rhs) const
		{
			return (this->_i + this->_c == rhs._i + rhs._c);
		}

		bool	operator<(Foo const &rhs) const
		{
			return (this->_i + this->_c < rhs._i + rhs._c);
		}

		bool	operator<=(Foo const &rhs) const
		{
			return (*this < rhs || *this == rhs);
		}

		bool	operator>(Foo const &rhs) const
		{
			return (!(*this <= rhs));
		}

		bool	operator>=(Foo const &rhs) const
		{
			return (!(*this < rhs));
		}

		std::string	getName(void) const {return (this->_name);}
		int			getInt(void) const {return (this->_i);}
		char		getChar(void) const {return (this->_c);}

	private:
		std::string const	_name;
		int					_i;
		char				_c;
};

std::ostream	&operator<<(std::ostream &out, Foo const &rhs)
{
	out << rhs.getName() << " I:" << rhs.getInt() << " C:" << rhs.getChar();
	return (out);
}

template <typename T>
void	test(T &first, T &second)
{
	std::cout << "First: " << first << std::endl
		<< "Second: " << second << std::endl;
	std::cout << "Max: " << max(first, second) << std::endl;
	std::cout << "Min: " << min(first, second) << std::endl;
	std::cout << "Swap" << std::endl;
	swap(first, second);
	std::cout << "First: " << first << std::endl
		<< "Second: " << second << std::endl;
}

int	main(void)
{
	int		i1 = -1;
	int		i2 = 2;
	char	c1 = '*';
	char	c2 = '2';
	Foo		f1("First", 0, '*');
	Foo		f2("Second", 50, '\a');

	test<int>(i1, i2);
	test<char>(c1, c2);
	test<Foo>(f1, f2);
	return (111);
}
