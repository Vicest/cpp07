/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:43:44 by vicmarti          #+#    #+#             */
/*   Updated: 2022/02/22 21:00:37 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
T const	&min(T const &a, T const &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T const	&max(T const &a, T const &b)
{
	if (a > b)
		return (a);
	return (b);
}

template <typename T>
void	swap(T &a, T &b)
{
	T aux = a;

	a = b;
	b = aux;
}
#endif

