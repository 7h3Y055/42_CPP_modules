#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


int	Account::getNbAccounts( void ){
    return _nbAccounts;
}

int	Account::getTotalAmount( void ){
    return _totalAmount;
}

int	Account::getNbDeposits( void ){
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){
    return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ){
    Account::_displayTimestamp();
    std::cout << "accounts:" << getNbAccounts();
    std::cout << ";total:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits();
    std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ):_accountIndex(_nbAccounts),\
                                        _amount(initial_deposit),\
                                        _nbDeposits(0),\
                                        _nbWithdrawals(0){
    _nbAccounts++;
    _totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void ){
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;

}


void	Account::makeDeposit( int deposit ){
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";deposit:" << deposit;
    _amount += deposit;
    std::cout << ";amount:" << _amount;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";withdrawal:";

    if (_amount - withdrawal < 0){
        std::cout << "refused" << std::endl;
        return 1;
    }
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << _amount;
    _nbWithdrawals++;
    std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return 0;
}

int 	Account::checkAmount( void ) const{
    return 0;
}

void	Account::displayStatus( void ) const{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;

}

void	Account::_displayTimestamp( void ){
    std::time_t time = std::time(NULL);
    std::tm *time_tm = std::localtime(&time);
    
    std::cout << "[" << time_tm->tm_year + 1900 ;
    std::cout << std::setw(2) << std::setfill('0') << time_tm->tm_mon + 1 ;
    std::cout << std::setw(2) << std::setfill('0') << time_tm->tm_mday << "_";
    std::cout << std::setw(2) << std::setfill('0') << time_tm->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << time_tm->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << time_tm->tm_sec;
    std::cout << "] ";
}