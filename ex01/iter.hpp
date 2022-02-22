/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:35:19 by vicmarti          #+#    #+#             */
/*   Updated: 2022/02/22 22:51:45 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <cstddef>

template<typename T>
void	iter(T arr[], std::size_t const len, void (*fun)(T const))
{
	if (!fun) //No fun allowed.
		return ;
	for (std::size_t i = 0; i < len; i++)
		fun(arr[i]);
}
#endif

