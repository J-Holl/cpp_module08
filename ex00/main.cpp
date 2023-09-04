/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:55:06 by jholl             #+#    #+#             */
/*   Updated: 2022/05/25 13:22:55 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iterator>

int main(void)
{
	// Test with vector vec_container
	std::vector<int>			vec_container(10, 50);
	std::vector<int>::const_iterator	it;
	//Normal situation
	try
	{
		it = easyfind(vec_container, 50);
		std::cout << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	//No occurence of 51 in vec_container
	try
	{
		it = easyfind(vec_container, 51);
		std::cout << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// Test with list vec_container
	std::list<int> lst_container;
	std::list<int>::const_iterator	it_lst;
	
	lst_container.push_back(200);
	lst_container.push_back(400);
	lst_container.push_back(1200);
	lst_container.push_back(600);
	lst_container.push_back(1200);

	//Normal situation
	try
	{
		it_lst = easyfind(lst_container, 1200);
		std::cout << *it_lst << std::endl;
		//verify that was the first occurence of 1200 and not the last
		std::advance(it_lst, -1);
		std::cout << *it_lst << std::endl;
		std::advance(it_lst, 2);
		std::cout << *it_lst << std::endl;
		std::advance(it_lst, 1);
		std::cout << *it_lst << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	//No occurence of 0 in lst_container
	try
	{
		it_lst = easyfind(lst_container, 0);
		std::cout << *it_lst << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
