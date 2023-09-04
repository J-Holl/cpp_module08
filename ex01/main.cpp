#include "Span.hpp"

int main(void)
{

	{
		Span toto = Span(5);

		toto.addNumber(6);
		toto.addNumber(3);
		toto.addNumber(17);
		toto.addNumber(9);
		toto.addNumber(11);

		std::cout << toto.shortestSpan() << std::endl;
		std::cout << toto.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		Span toto(50000);
		for (size_t i = 0; i < 50000; i++)
		{
			toto.addNumber(i + 1 + (i / 4));
		}
		std::cout << toto.shortestSpan() << std::endl;
		std::cout << toto.longestSpan() << std::endl;
		//Exception
		try
		{
			toto.addNumber(1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Span toto(1);
		toto.addNumber(1);
		//Exception
		try
		{
			toto.longestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			toto.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Span toto1;
			toto1.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

	}
	std::cout << std::endl;
	//Add in a single time a range of number with itterators
	{	
		Span toto(100);
		srand(time(NULL));
		std::vector<int> add_to_toto;
		for (size_t i = 0; i < 100; i++)
		{
			add_to_toto.push_back(std::rand());	
		}
		try
		{
			std::vector<int>::iterator it_start = add_to_toto.begin();
			std::vector<int>::iterator it_end = add_to_toto.end();
			toto.addNumberWithIt(it_start, it_end);
			std::cout << toto.shortestSpan() << std::endl;
			std::cout << toto.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
