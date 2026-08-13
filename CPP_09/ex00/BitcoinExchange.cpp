#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

/* ************************************************************************** */
/*                            Constructors & Destructor                       */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _database(other._database) {}

BitcoinExchange::~BitcoinExchange(void) {}


/* ************************************************************************** */
/*                         Copy assignment operator                           */
/* ************************************************************************** */

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_database = other._database;

	return *this;
}


/* ************************************************************************** */
/*                                  Helpers                                   */
/* ************************************************************************** */

std::string BitcoinExchange::trim(const std::string& str) const
{
	std::string::size_type start = str.find_first_not_of(" \t");
	std::string::size_type end = str.find_last_not_of(" \t");

	if (start == std::string::npos)
		return "";

	return str.substr(start, end - start + 1);
}

bool BitcoinExchange::isLeapYear(int year) const
{
	if (year % 400 == 0)
		return true;

	if (year % 100 == 0)
		return false;

	return (year % 4 == 0);
}


/* ************************************************************************** */
/*                              Date validation                              */
/* ************************************************************************** */

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.size() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;

		if (date[i] < '0' || date[i] > '9')
			return false;
	}

	int year;
	int month;
	int day;

	std::stringstream ssYear(date.substr(0, 4));
	std::stringstream ssMonth(date.substr(5, 2));
	std::stringstream ssDay(date.substr(8, 2));

	ssYear >> year;
	ssMonth >> month;
	ssDay >> day;

	if (month < 1 || month > 12)
		return false;

	int daysInMonth[] =
	{
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

	if (month == 2 && isLeapYear(year))
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}


/* ************************************************************************** */
/*                              Value validation                              */
/* ************************************************************************** */

bool BitcoinExchange::isValidValue(const std::string& value) const
{
	if (value.empty())
		return false;

	std::stringstream ss(value);
	double number;
	char extra;

	ss >> number;

	if (ss.fail())
		return false;

	if (ss >> extra)
		return false;

	if (number < 0)
		return false;

	if (number > 1000)
		return false;

	return true;
}

bool BitcoinExchange::isNegativeNumber(const std::string& value) const
{
	if (value.empty())
		return false;

	std::stringstream ss(value);
	double number;

	ss >> number;

	if (ss.fail())
		return false;

	return (number < 0);
}

bool BitcoinExchange::isTooLarge(const std::string& value) const
{
	if (value.empty())
		return false;

	std::stringstream ss(value);
	double number;

	ss >> number;

	if (ss.fail())
		return false;

	return (number > 1000);
}

double BitcoinExchange::parseValue(const std::string& value) const
{
	std::stringstream ss(value);
	double number;

	ss >> number;

	if (ss.fail())
		throw std::runtime_error("invalid value");

	return number;
}


/* ************************************************************************** */
/*                                Database                                    */
/* ************************************************************************** */

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("could not open database");

	std::string line;

	if (!std::getline(file, line))
		throw std::runtime_error("empty database");

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::stringstream ss(line);

		std::string date;
		std::string rate;

		if (!std::getline(ss, date, ','))
			continue;

		if (!std::getline(ss, rate))
			continue;

		date = trim(date);
		rate = trim(rate);

		if (!isValidDate(date))
			continue;

		if (!isValidValue(rate))
			continue;

		_database[date] = parseValue(rate);
	}
}


/* ************************************************************************** */
/*                              Exchange rate                                 */
/* ************************************************************************** */

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
	if (_database.empty())
		throw std::runtime_error("database is empty");

	std::map<std::string, double>::const_iterator it;

	it = _database.lower_bound(date);

	if (it != _database.end() && it->first == date)
		return it->second;

	if (it == _database.begin())
		throw std::runtime_error("date is before database");

	--it;

	return it->second;
}


/* ************************************************************************** */
/*                                Input                                       */
/* ************************************************************************** */

void BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("could not open file");

	std::string line;

	if (!std::getline(file, line))
		return;

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::string::size_type separator = line.find('|');

		if (separator == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, separator));
		std::string value = trim(line.substr(separator + 1));

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!isValidValue(value))
		{
			if (isNegativeNumber(value))
				std::cerr << "Error: not a positive number." << std::endl;
			else if (isTooLarge(value))
				std::cerr << "Error: too large a number." << std::endl;
			else
				std::cerr << "Error: bad input => " << line << std::endl;

			continue;
		}

		try
		{
			double amount = parseValue(value);
			double rate = getExchangeRate(date);

			std::cout << date
					<< " => " << amount
					<< " = " << amount * rate
					<< std::endl;
		}
		catch (const std::exception&)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
}
