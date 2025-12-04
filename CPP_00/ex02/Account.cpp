/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:09:48 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/04 17:12:25 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

# define BLUE  "\033[34m"
# define RESET "\033[0m"

// Initialize static attr.
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Timestap function
void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);
	std::tm *pt_time = std::localtime(&now);

	std::cout	<< "["
				<< (pt_time->tm_year + 1900)
				<< (pt_time->tm_mon < 9 ? "0" : "") << (pt_time->tm_mon + 1)
				<< (pt_time->tm_mday < 10 ? "0" : "") << pt_time->tm_mday
				<< "_"
				<< (pt_time->tm_hour < 10 ? "0" : "") << pt_time->tm_hour
				<< (pt_time->tm_min < 10 ? "0" : "") << pt_time->tm_min
				<< (pt_time->tm_sec < 10 ? "0" : "") << pt_time->tm_sec
				<< "] ";
}

// Constructor -> With inicializer list
Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();

	std::cout	<< "index:" << BLUE << _accountIndex << RESET
				<< ";amount:" << BLUE << _amount << RESET
				<< ";created" << std::endl;
}

// Destructor
Account::~Account(void)
{
	_displayTimestamp();
	std::cout	<< "index:" << BLUE << _accountIndex << RESET
				<< ";amount:" << BLUE << _amount << RESET
				<< ";closed" << std::endl;
}

// Static Getters
int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

// Functions
// Display infos about all Accounts together
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< "accounts:" << BLUE << getNbAccounts() << RESET
				<< ";total:" << BLUE << getTotalAmount() << RESET
				<< ";deposits:" << BLUE << getNbDeposits() << RESET
				<< ";withdrawals:" << BLUE << getNbWithdrawals() << RESET
				<< std::endl;
}

// Make deposit
void	Account::makeDeposit(int deposit)
{
	int	previous = _amount;

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout	<< "index:" << BLUE << _accountIndex << RESET
				<< ";p_amount:" << BLUE << previous << RESET
				<< ";deposit:" << BLUE << deposit << RESET
				<< ";amount:" << BLUE << _amount << RESET
				<< ";nb_deposits:" << BLUE << _nbDeposits << RESET
				<< std::endl;
}

// Make Withdrawal
bool	Account::makeWithdrawal(int withdrawal)
{
	int	previous = _amount;

	_displayTimestamp();
	std::cout	<< "index:" << BLUE << _accountIndex << RESET
				<< ";p_amount:" << BLUE << previous << RESET;

	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -=withdrawal;
	_totalNbWithdrawals++;

	std::cout	<< ";withdrawal:" << BLUE << withdrawal << RESET
				<< ";amount:" << BLUE << _amount << RESET
				<< ";nb_withdrawals:" << BLUE << _nbWithdrawals << RESET
				<< std::endl;

	return true;
}

// Display Account info (specific)
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout	<< "index:" << BLUE << _accountIndex << RESET
				<< ";amount:" << BLUE << _amount << RESET
				<< ";deposits:" << BLUE << _nbDeposits << RESET
				<< ";withdrawals:" << BLUE << _nbWithdrawals << RESET
				<< std::endl;
}