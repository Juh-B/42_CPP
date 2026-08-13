#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe(void);

		void parseInput(int argc, char **argv);

		void sortVector(void);
		void sortDeque(void);

		const std::vector<int>& getVector(void) const;
		const std::deque<int>& getDeque(void) const;

		double getVectorTime(void) const;
		double getDequeTime(void) const;

	private:
		struct Node
		{
			int value;
			int id;

			Node(int v = 0, int i = 0)
				: value(v), id(i) {}
		};

		struct Pair
		{
			Node small;
			Node large;

			Pair(const Node& s, const Node& l)
				: small(s), large(l) {}
		};

		std::vector<int>	_vector;
		std::deque<int>		_deque;

		double				_vectorTime;
		double				_dequeTime;

		int parseNumber(const std::string& str) const;
		bool isValidNumber(const std::string& str) const;

		void fordJohnsonVector(std::vector<Node>& numbers);
		void fordJohnsonDeque(std::deque<Node>& numbers);

		std::vector<int> generateJacobsthal(int size) const;

		std::vector<Node>::iterator
			binarySearchVector(std::vector<Node>& chain,
								int value,
								std::vector<Node>::iterator end);

		std::deque<Node>::iterator
			binarySearchDeque(std::deque<Node>& chain,
								int value,
								std::deque<Node>::iterator end);
};

#endif
