/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:58:24 by jholl             #+#    #+#             */
/*   Updated: 2022/05/25 18:28:53 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{

	{
		MutantStack<int> toto_mutant_stack;

		toto_mutant_stack.push(5);
		toto_mutant_stack.push(10);
		
		//Check if Member stack functions are correctly herrited
		std::cout << ".size(): " << toto_mutant_stack.size() << std::endl;
		std::cout << ".top(): " << toto_mutant_stack.top() << std::endl;
		toto_mutant_stack.pop();
		std::cout << ".size() after a .pop(): " << toto_mutant_stack.size() << std::endl;
		toto_mutant_stack.push(10);
		std::cout << ".top() after .push(10): " << toto_mutant_stack.top() << std::endl;
		
		toto_mutant_stack.push(15);
		toto_mutant_stack.push(20);


		//Check new iterator
		MutantStack<int>::it it_start = toto_mutant_stack.begin();
		MutantStack<int>::it it_end = toto_mutant_stack.end();
		it_end--;
		
		std::cout << "iterator it_start "<< *it_start << std::endl;
		std::cout << "iterator it_end "<< *it_end << std::endl;
		++it_start;
		--it_end;
		std::cout << "iterator it_start incremented "<< *it_start << std::endl;
		std::cout << "iterator it_end decremented "<< *it_end << std::endl;
		it_start--;
		it_end++;
		std::cout << "iterator it_start decremented " << *it_start << std::endl;
		std::cout << "iterator it_end incremented " << *it_end << std::endl;

		it_end++;
		while (it_start != it_end)
		{
			std::cout << *it_start << std::endl;
			it_start++;
		}
	}
	std::cout << std::endl;
	//compare comportement with std::list
	{
		std::list<int> toto_list;

		toto_list.push_back(5);
		toto_list.push_back(10);
		
		std::cout << ".size(): " << toto_list.size() << std::endl;
		std::cout << ".back(): " << toto_list.back() << std::endl;
		toto_list.pop_back();
		std::cout << ".size() after a .pop_back(): " << toto_list.size() << std::endl;
		toto_list.push_back(10);
		std::cout << ".back() after .push_back(10): " << toto_list.back() << std::endl;
		
		toto_list.push_back(15);
		toto_list.push_back(20);


		std::list<int>::iterator it_start = toto_list.begin();
		std::list<int>::iterator it_end = toto_list.end();
		it_end--;
		
		std::cout << "iterator it_start "<< *it_start << std::endl;
		std::cout << "iterator it_end "<< *it_end << std::endl;
		++it_start;
		--it_end;
		std::cout << "iterator it_start incremented "<< *it_start << std::endl;
		std::cout << "iterator it_end decremented "<< *it_end << std::endl;
		it_start--;
		it_end++;
		std::cout << "iterator it_start decremented " << *it_start << std::endl;
		std::cout << "iterator it_end incremented " << *it_end << std::endl;

		it_end++;
		while (it_start != it_end)
		{
			std::cout << *it_start << std::endl;
			it_start++;
		}
	}
	return (0);
}
