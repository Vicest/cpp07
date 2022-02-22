/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:28:53 by vicmarti          #+#    #+#             */
/*   Updated: 2022/02/22 22:50:58 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <iostream>
#include <iomanip>

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

void	fubar(int const n)
{
	std::cout.width(8);
	std::cout.setf(std::ios::left);
	std::cout << std::boolalpha << n << ((n % 2) == 0) << std::endl;
}

void	hideLower(char const c)
{
	if (islower(c))
		std::cout << "*";
	else if (c)
		std::cout << c;
	else
		std::cout << std::endl;
}

void	printLen(std::string const s)
{
	std::cout.setf(std::ios::left);
	std::cout << "Len:" << std::setw(5) << s.size() << s << std::endl;
}

int	main(void)
{
	int			iarr[] = {1, 4, 0, -3, 12, 999, -1337};
	char		carr[] = "Hello World";
	std::string	sarr[] = {"chaine1", "chaine3", "potatoes", "bingo!"};
	Foo			farr[] = {Foo("1", 50, '\a')};

	iter<int>(iarr, 7, &fubar);
	iter(carr, 12, &hideLower);
	iter(sarr, 4, &printLen);
	return (111);
}
