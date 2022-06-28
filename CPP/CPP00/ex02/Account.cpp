#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	time_t	temp;
	tm		*time_info;

	time(&temp);
	time_info = localtime(&temp);
	std::cout << "[" << time_info->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2)  << time_info->tm_mon + 1
		<< std::setw(2) << time_info->tm_mday << "_" 
		<< std::setw(2) << time_info->tm_hour
		<< std::setw(2) << time_info->tm_min
		<< std::setw(2) << time_info->tm_sec << "] ";
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";created" << std::endl;
}
