#include "PmergeMe.hpp"

#include <iostream>
#include <stdexcept>

int main(int argc, char **argv)
{
	try
	{
		PmergeMe pmergeMe;

		pmergeMe.parseInput(argc, argv);

		const std::vector<int>& before = pmergeMe.getVector();

		std::cout << "Before:";

		for (std::vector<int>::const_iterator it = before.begin();
			 it != before.end(); ++it)
		{
			std::cout << " " << *it;
		}

		std::cout << std::endl;

		pmergeMe.sortVector();
		pmergeMe.sortDeque();

		const std::vector<int>& after = pmergeMe.getVector();

		std::cout << "After:";

		for (std::vector<int>::const_iterator it = after.begin();
			 it != after.end(); ++it)
		{
			std::cout << " " << *it;
		}

		std::cout << std::endl;

		std::cout << "Time to process a range of "
				  << after.size()
				  << " elements with std::vector : "
				  << pmergeMe.getVectorTime()
				  << " us"
				  << std::endl;

		std::cout << "Time to process a range of "
				  << after.size()
				  << " elements with std::deque : "
				  << pmergeMe.getDequeTime()
				  << " us"
				  << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	return 0;
}
