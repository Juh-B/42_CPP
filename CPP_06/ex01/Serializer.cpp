/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:12:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer::~Serializer(void) {}


/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}

/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
