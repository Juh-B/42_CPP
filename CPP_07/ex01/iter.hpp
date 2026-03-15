/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:24:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:22:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T>
void iter(T *array, const size_t length, void (*func)(T &))
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

template <typename T>
void iter(const T *array, const size_t length, void (*func)(const T &))
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

#endif
