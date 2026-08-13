#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN
{
	public:
		RPN(void);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN(void);

		int calculate(const std::string& expression) const;

	private:
		bool isOperator(char c) const;
		bool isNumber(char c) const;
		int applyOperation(int left, int right, char op) const;
};

#endif
