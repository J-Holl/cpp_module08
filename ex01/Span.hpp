/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:24:16 by jholl             #+#    #+#             */
/*   Updated: 2022/05/25 14:27:43 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <string>
# include <vector>

class Span
{

	public:

		Span();
		Span(unsigned int n);
		Span(Span const & cpy);
		~Span();

		Span & operator=(Span const & rhs);

		void			addNumber(int const nb);
		void			addNumberWithIt(std::vector<int>::iterator it_start, std::vector<int>::iterator it_end);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		
		
		class EmptyException: public std::exception
		{
			const char * what() const throw()
			{
				return ("Exception. Array is empty.");
			}
		};
		class SoloException: public std::exception
		{
			const char * what() const throw()
			{
				return ("Exception. You need a second value for a distance.");
			}
		};
		class MaxCapacityException: public std::exception
		{
			const char * what() const throw()
			{
				return ("Exception. You reached the maximum capacity.");
			}
		};

	
	private:
		unsigned int	_max_size;
		std::vector<int>	_vec;

};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif
