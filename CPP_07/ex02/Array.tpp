/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:12:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void) : _data(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _data;
}


/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _data;

		_size = other._size;
		_data = new T[_size];

		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return *this;
}

/* ************************************************************************** */
/*                                Operator                                    */
/* ************************************************************************** */

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::exception();
	return _data[index];
}

/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}
