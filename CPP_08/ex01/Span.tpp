/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:22:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:12:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                Methods                                     */
/* ************************************************************************** */

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	if (_numbers.size() + std::distance(begin, end) > _maxSize)
		throw std::runtime_error("Not enough space");

	_numbers.insert(_numbers.end(), begin, end);
}
