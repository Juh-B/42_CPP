#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange(void);

		void loadDatabase(const std::string& filename);
		void processInput(const std::string& filename);

	private:
		std::map<std::string, double> _database;

		bool isValidDate(const std::string& date) const;
		bool isLeapYear(int year) const;
		bool isValidValue(const std::string& value) const;
		bool isNegativeNumber(const std::string& value) const;
		bool isTooLarge(const std::string& value) const;

		double parseValue(const std::string& value) const;
		double getExchangeRate(const std::string& date) const;

		std::string trim(const std::string& str) const;
};

#endif
