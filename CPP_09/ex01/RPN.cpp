#include "RPN.hpp"

#include <stdexcept>

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

RPN::RPN(void)
{
}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN::~RPN(void)
{
}

/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return *this;
}

/* ************************************************************************** */
/*                                Helpers                                     */
/* ************************************************************************** */

bool RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::isNumber(char c) const
{
	return (c >= '0' && c <= '9');
}

int RPN::applyOperation(int left, int right, char op) const
{
	switch (op)
	{
		case '+':
			return left + right;

		case '-':
			return left - right;

		case '*':
			return left * right;

		case '/':
			if (right == 0)
				throw std::runtime_error("division by zero");
			return left / right;
	}

	throw std::runtime_error("invalid operator");
}

/* ************************************************************************** */
/*                                Calculation                                 */
/* ************************************************************************** */

int RPN::calculate(const std::string& expression) const
{
	std::stack<int> numbers;

	for (std::string::size_type i = 0; i < expression.size(); i++)
	{
		char token = expression[i];

		if (token == ' ')
			continue;

		if (isNumber(token))
		{
			numbers.push(token - '0');
		}
		else if (isOperator(token))
		{
			if (numbers.size() < 2)
				throw std::runtime_error("invalid expression");

			int right = numbers.top();
			numbers.pop();

			int left = numbers.top();
			numbers.pop();

			int result = applyOperation(left, right, token);

			numbers.push(result);
		}
		else
		{
			throw std::runtime_error("invalid token");
		}
	}

	if (numbers.size() != 1)
		throw std::runtime_error("invalid expression");

	return numbers.top();
}
