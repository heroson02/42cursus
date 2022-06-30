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

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts() << ";"
				<< "total:"	<< getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "dwithdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void )	const
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:"	<< _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int	p_amount = _amount;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:"	<< p_amount << ";"
				<< "deposits:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = _amount;
	_amount -= withdrawal;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:"	<< p_amount << ";";
	if (_amount >= 0)
	{
		_totalAmount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout	<< "withdrawal:" << withdrawal << ";"
					<< "amount:" << _amount << ";"
					<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (1);
	}
	else
	{
		_amount = p_amount;
		std::cout << "withdrawal:refused" << std::endl;
		return (0);
	}
	return (0);
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:"	<< _amount << ";"
				<< "closed"	<< std::endl;
}
