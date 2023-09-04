/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:51:15 by jholl             #+#    #+#             */
/*   Updated: 2022/05/25 18:28:03 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>

template < typename T >
class MutantStack:
public std::stack<T>
{
	public: 

		MutantStack();
		MutantStack(MutantStack<T> const & cpy);

		~MutantStack(void);

		MutantStack & operator=(MutantStack<T> const & cpy);

		typedef typename std::stack<T>::container_type::iterator it;
		typedef typename std::stack<T>::container_type::const_iterator it_c;

		it end();
		it begin();
		it_c begin() const;
		it_c end() const;
};

//Constructor
template < typename T >
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

//Cpy
template < typename T >
MutantStack<T>::MutantStack(MutantStack<T> const & cpy)
{
	*this = cpy;
}

//Overload assignement
template < typename T >
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const & cpy)
{
	this->c = cpy.c;
	return (*this);
}

//Destructor
template < typename T >
MutantStack<T>::~MutantStack()
{
}

// Member functions
template < typename T >
typename MutantStack<T>::it MutantStack<T>::begin()
{
	return (this->c.begin());
}

template < typename T >
typename MutantStack<T>::it MutantStack<T>::end()
{
	return (this->c.end());
}

template < typename T >
typename MutantStack<T>::it_c MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template < typename T >
typename MutantStack<T>::it_c MutantStack<T>::end() const
{
	return (this->c.end());
}

#endif
