/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:43:32 by jholl             #+#    #+#             */
/*   Updated: 2022/05/25 13:12:12 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <stdexcept>
# include <list>
# include <vector>
# include <algorithm>

class CantFindXException:
public std::exception
{
	public:
		virtual const char * what() const throw()
		{
			return ("There is no occurence of the number you type in the container.");
		}
};

template < typename T >
typename T::const_iterator	easyfind(T const & container, int const x)
{
	typename T::const_iterator ret_it = std::find(container.begin(), container.end(), x);
	if (ret_it == container.end())
		throw CantFindXException();
	else
		return (ret_it);
};

#endif
