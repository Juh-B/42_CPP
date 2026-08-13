#include "PmergeMe.hpp"

#include <cstdlib>
#include <climits>
#include <stdexcept>
#include <ctime>

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

PmergeMe::PmergeMe(void)
	: _vectorTime(0.0),
	  _dequeTime(0.0)
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
	: _vector(other._vector),
	  _deque(other._deque),
	  _vectorTime(other._vectorTime),
	  _dequeTime(other._dequeTime)
{
}

PmergeMe::~PmergeMe(void)
{
}

/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
		_vectorTime = other._vectorTime;
		_dequeTime = other._dequeTime;
	}

	return *this;
}

/* ************************************************************************** */
/*                                Validation                                  */
/* ************************************************************************** */

bool PmergeMe::isValidNumber(const std::string& str) const
{
	if (str.empty())
		return false;

	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return false;
	}

	return true;
}

int PmergeMe::parseNumber(const std::string& str) const
{
	if (!isValidNumber(str))
		throw std::runtime_error("invalid number");

	long number = std::strtol(str.c_str(), NULL, 10);

	if (number > INT_MAX)
		throw std::runtime_error("number too large");

	if (number <= 0)
		throw std::runtime_error("number must be positive");

	return static_cast<int>(number);
}

/* ************************************************************************** */
/*                                Input                                       */
/* ************************************************************************** */

void PmergeMe::parseInput(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("no input");

	_vector.clear();
	_deque.clear();

	for (int i = 1; i < argc; i++)
	{
		int number = parseNumber(argv[i]);

		_vector.push_back(number);
		_deque.push_back(number);
	}
}

/* ************************************************************************** */
/*                         Jacobsthal sequence                               */
/* ************************************************************************** */

std::vector<int> PmergeMe::generateJacobsthal(int size) const
{
	std::vector<int> order;

	if (size <= 1)
		return order;

	int previous = 1;
	int current = 3;

	while (previous < size)
	{
		int end = current;

		if (end > size)
			end = size;

		for (int i = end; i > previous; i--)
			order.push_back(i);

		previous = current;
		current = current * 2 + previous;
	}

	return order;
}

/* ************************************************************************** */
/*                         Vector - Binary Search                             */
/* ************************************************************************** */

std::vector<PmergeMe::Node>::iterator
PmergeMe::binarySearchVector(std::vector<Node>& chain,
							  int value,
							  std::vector<Node>::iterator end)
{
	std::vector<Node>::iterator first = chain.begin();

	while (first < end)
	{
		std::vector<Node>::iterator middle =
			first + (end - first) / 2;

		if (middle->value < value)
			first = middle + 1;
		else
			end = middle;
	}

	return first;
}

/* ************************************************************************** */
/*                         Deque - Binary Search                              */
/* ************************************************************************** */

std::deque<PmergeMe::Node>::iterator
PmergeMe::binarySearchDeque(std::deque<Node>& chain,
							 int value,
							 std::deque<Node>::iterator end)
{
	std::deque<Node>::iterator first = chain.begin();

	while (first < end)
	{
		std::deque<Node>::iterator middle =
			first + (end - first) / 2;

		if (middle->value < value)
			first = middle + 1;
		else
			end = middle;
	}

	return first;
}

/* ************************************************************************** */
/*                         Ford-Johnson - Vector                              */
/* ************************************************************************** */

void PmergeMe::fordJohnsonVector(std::vector<Node>& numbers)
{
	if (numbers.size() <= 1)
		return;

	std::vector<Pair> pairs;
	std::vector<Node> larger;

	for (std::vector<Node>::size_type i = 0;
		 i + 1 < numbers.size(); i += 2)
	{
		Node first = numbers[i];
		Node second = numbers[i + 1];

		if (first.value < second.value)
			pairs.push_back(Pair(first, second));
		else
			pairs.push_back(Pair(second, first));

		larger.push_back(pairs.back().large);
	}

	bool hasStraggler = (numbers.size() % 2 != 0);
	Node straggler;

	if (hasStraggler)
		straggler = numbers.back();

	/*
	 * Recursively sort the larger elements.
	 */
	fordJohnsonVector(larger);

	/*
	 * Rebuild the pairs in the same order as the sorted
	 * larger elements.
	 */
	std::vector<Pair> orderedPairs;

	for (std::vector<Node>::iterator largeIt = larger.begin();
		 largeIt != larger.end(); ++largeIt)
	{
		for (std::vector<Pair>::iterator pairIt = pairs.begin();
			 pairIt != pairs.end(); ++pairIt)
		{
			if (pairIt->large.id == largeIt->id)
			{
				orderedPairs.push_back(*pairIt);
				break;
			}
		}
	}

	/*
	 * Main chain:
	 *
	 * b1, a1, a2, a3, ...
	 *
	 * where b is the smaller element and a is
	 * the corresponding larger element.
	 */
	std::vector<Node> chain;

	chain.push_back(orderedPairs[0].small);

	for (std::vector<Node>::iterator it = larger.begin();
		 it != larger.end(); ++it)
	{
		chain.push_back(*it);
	}

	/*
	 * Insert the remaining smaller elements using
	 * the Jacobsthal insertion order.
	 */
	std::vector<int> order =
		generateJacobsthal(static_cast<int>(orderedPairs.size()));

	for (std::vector<int>::iterator orderIt = order.begin();
		 orderIt != order.end(); ++orderIt)
	{
		int index = *orderIt - 1;

		if (index <= 0 ||
			index >= static_cast<int>(orderedPairs.size()))
			continue;

		int value = orderedPairs[index].small.value;
		int partnerId = orderedPairs[index].large.id;

		std::vector<Node>::iterator partner = chain.begin();

		while (partner != chain.end() &&
			   partner->id != partnerId)
			++partner;

		std::vector<Node>::iterator position =
			binarySearchVector(chain, value, partner);

		chain.insert(position, orderedPairs[index].small);
	}

	/*
	 * If the input has an odd number of elements,
	 * insert the remaining straggler.
	 */
	if (hasStraggler)
	{
		std::vector<Node>::iterator position =
			binarySearchVector(chain, straggler.value, chain.end());

		chain.insert(position, straggler);
	}

	numbers = chain;
}

/* ************************************************************************** */
/*                          Ford-Johnson - Deque                              */
/* ************************************************************************** */

void PmergeMe::fordJohnsonDeque(std::deque<Node>& numbers)
{
	if (numbers.size() <= 1)
		return;

	std::deque<Pair> pairs;
	std::deque<Node> larger;

	for (std::deque<Node>::size_type i = 0;
		 i + 1 < numbers.size(); i += 2)
	{
		Node first = numbers[i];
		Node second = numbers[i + 1];

		if (first.value < second.value)
			pairs.push_back(Pair(first, second));
		else
			pairs.push_back(Pair(second, first));

		larger.push_back(pairs.back().large);
	}

	bool hasStraggler = (numbers.size() % 2 != 0);
	Node straggler;

	if (hasStraggler)
		straggler = numbers.back();

	/*
	 * Recursively sort the larger elements.
	 */
	fordJohnsonDeque(larger);

	/*
	 * Rebuild the pairs according to the sorted
	 * larger elements.
	 */
	std::deque<Pair> orderedPairs;

	for (std::deque<Node>::iterator largeIt = larger.begin();
		 largeIt != larger.end(); ++largeIt)
	{
		for (std::deque<Pair>::iterator pairIt = pairs.begin();
			 pairIt != pairs.end(); ++pairIt)
		{
			if (pairIt->large.id == largeIt->id)
			{
				orderedPairs.push_back(*pairIt);
				break;
			}
		}
	}

	/*
	 * Main chain:
	 *
	 * b1, a1, a2, a3, ...
	 */
	std::deque<Node> chain;

	chain.push_back(orderedPairs[0].small);

	for (std::deque<Node>::iterator it = larger.begin();
		 it != larger.end(); ++it)
	{
		chain.push_back(*it);
	}

	/*
	 * Jacobsthal insertion order.
	 */
	std::vector<int> order =
		generateJacobsthal(static_cast<int>(orderedPairs.size()));

	for (std::vector<int>::iterator orderIt = order.begin();
		 orderIt != order.end(); ++orderIt)
	{
		int index = *orderIt - 1;

		if (index <= 0 ||
			index >= static_cast<int>(orderedPairs.size()))
			continue;

		int value = orderedPairs[index].small.value;
		int partnerId = orderedPairs[index].large.id;

		std::deque<Node>::iterator partner = chain.begin();

		while (partner != chain.end() &&
			   partner->id != partnerId)
			++partner;

		std::deque<Node>::iterator position =
			binarySearchDeque(chain, value, partner);

		chain.insert(position, orderedPairs[index].small);
	}

	/*
	 * Insert straggler.
	 */
	if (hasStraggler)
	{
		std::deque<Node>::iterator position =
			binarySearchDeque(chain, straggler.value, chain.end());

		chain.insert(position, straggler);
	}

	numbers = chain;
}

/* ************************************************************************** */
/*                              Sorting                                       */
/* ************************************************************************** */

void PmergeMe::sortVector(void)
{
	std::clock_t start = std::clock();

	std::vector<Node> numbers;

	for (std::vector<int>::const_iterator it = _vector.begin();
		 it != _vector.end(); ++it)
	{
		int id = static_cast<int>(numbers.size());
		numbers.push_back(Node(*it, id));
	}

	fordJohnsonVector(numbers);

	_vector.clear();

	for (std::vector<Node>::const_iterator it = numbers.begin();
		 it != numbers.end(); ++it)
	{
		_vector.push_back(it->value);
	}

	std::clock_t end = std::clock();

	_vectorTime =
		static_cast<double>(end - start) * 1000000.0
		/ static_cast<double>(CLOCKS_PER_SEC);
}

void PmergeMe::sortDeque(void)
{
	std::clock_t start = std::clock();

	std::deque<Node> numbers;

	for (std::deque<int>::const_iterator it = _deque.begin();
		 it != _deque.end(); ++it)
	{
		int id = static_cast<int>(numbers.size());
		numbers.push_back(Node(*it, id));
	}

	fordJohnsonDeque(numbers);

	_deque.clear();

	for (std::deque<Node>::const_iterator it = numbers.begin();
		 it != numbers.end(); ++it)
	{
		_deque.push_back(it->value);
	}

	std::clock_t end = std::clock();

	_dequeTime =
		static_cast<double>(end - start) * 1000000.0
		/ static_cast<double>(CLOCKS_PER_SEC);
}

/* ************************************************************************** */
/*                                Getters                                     */
/* ************************************************************************** */

const std::vector<int>& PmergeMe::getVector(void) const
{
	return _vector;
}

const std::deque<int>& PmergeMe::getDeque(void) const
{
	return _deque;
}

double PmergeMe::getVectorTime(void) const
{
	return _vectorTime;
}

double PmergeMe::getDequeTime(void) const
{
	return _dequeTime;
}
