/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:24:09 by jholl             #+#    #+#             */
/*   Updated: 2022/05/25 14:28:55 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//Constructor
Span::Span():
_max_size(0)
{
}

Span::Span(unsigned int n): _max_size(n)
{
}

Span::Span(const Span & cpy):
_max_size(cpy._max_size), _vec(cpy._vec)
{
}

//Destructor
Span::~Span()
{
}

//Overload assignement
Span &				Span::operator=( Span const & rhs )
{
	_max_size = rhs._max_size;
	_vec = rhs._vec;
	return (*this);
}


//Member function
void	Span::addNumber(int const nb)
{
	if (_vec.size() >= _max_size)
		throw MaxCapacityException();
	_vec.push_back(nb);
}

void Span::addNumberWithIt(std::vector<int>::iterator it_start, std::vector<int>::iterator it_end)
{
	if (_vec.size() >= _max_size)
		throw Span::MaxCapacityException();
	else
		_vec.insert(_vec.end(), it_start, it_end);
	if (_vec.size() > _max_size)
		throw Span::MaxCapacityException();
}

unsigned int	Span::longestSpan(void)
{
	if (!_vec.size())
		throw EmptyException();
	if (_vec.size() == 1)
		throw SoloException();
	std::vector<int>::iterator max = std::max_element(_vec.begin(), _vec.end());
	std::vector<int>::iterator min = std::min_element(_vec.begin(), _vec.end());

	return (*max - *min);
}

unsigned int	Span::shortestSpan(void)
{
	if (!_vec.size())
		throw EmptyException();
	if (_vec.size() == 1)
		throw SoloException();
	std::vector<int>	vec_sorted(_vec);
	unsigned int		lf_shortest_span = longestSpan();

	std::sort(vec_sorted.begin(), vec_sorted.end());
	for (std::vector<int>::iterator it = _vec.begin(); it < _vec.end() - 1; it++)
	{
		if (static_cast<unsigned int>(*(it + 1) - *it) < lf_shortest_span)
			lf_shortest_span = *(it + 1) - *it;
	}
	return (lf_shortest_span);
}
