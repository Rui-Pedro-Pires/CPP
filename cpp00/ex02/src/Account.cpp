#include <ctime>
#include <iostream>
#include <iomanip>
#include "../includes/Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _displayTimestamp();
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _accountIndex = getNbAccounts();
    _nbAccounts++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";closed" << std::endl;
}

void    Account::_displayTimestamp()
{
    std::time_t time_var;
    std::tm *time_struct;
    
    time(&time_var);
    time_struct = localtime(&time_var);
    std::cout << "[" << time_struct->tm_year + 1900;
    std::cout << std::setfill('0') << std::setw(2) << time_struct->tm_mon;
    std::cout << std::setfill('0') << std::setw(2) << time_struct->tm_mday;
    std::cout << "_" << time_struct->tm_hour << time_struct->tm_min << time_struct->tm_sec << "] ";
}

void    Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts();
    std::cout << ";total:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits();
    std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    if (deposit > 0)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex;
        std::cout << ";p_amount:" << checkAmount();
        std::cout << ";deposit:" << deposit;
        _amount += deposit;
        _totalAmount += deposit;
        std::cout << ";amount:" << checkAmount();
        _nbDeposits++;
        _totalNbDeposits++;
        std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
    }
}

bool    Account::makeWithdrawal(int withdrawal)
{
    if (checkAmount() - withdrawal >= 0)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex;
        std::cout << ";p_amount:" << checkAmount();
        std::cout << ";withdrawal:" << withdrawal;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        std::cout << ";amount:" << checkAmount();
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
        _displayTimestamp();

    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << checkAmount();
    std::cout << ";withdrawal:" << "refused" << std::endl;
    return (false);
}

int     Account::checkAmount() const
{
    return (_amount);
}

void    Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int   Account::getNbAccounts()
{
    return (_nbAccounts);
}

int   Account::getNbDeposits()
{
    return(_totalNbDeposits);
}

int   Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}

int   Account::getTotalAmount()
{
    return (_totalAmount);
}