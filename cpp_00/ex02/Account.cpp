/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:55:03 by segarcia          #+#    #+#             */
/*   Updated: 2023/04/03 12:41:50 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

// -----------------
// PRIVATE METHODS
// -----------------

int Account::getNbAccounts( void ) {
    return (Account::_nbAccounts);
}

int Account::getTotalAmount( void ) {
    return (Account::_totalAmount);
}

int Account::getNbDeposits( void ) {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void ) {
    return (Account::_totalNbWithdrawals);
}

void    Account::displayAccountsInfos( void ) {
    Account::_displayTimestamp();
    std::cout   << "accounts:" << Account::getNbAccounts() << ";"
                << "total:" << Account::getTotalAmount() << ";"
                << "deposits:" << Account::getNbDeposits() << ";"
                << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp(){
    std::time_t now = std::time(NULL);
    std::cout   << "[" << 1900 + std::localtime(&now)->tm_year
                << 1 + std::localtime(&now)->tm_mon
                << std::localtime(&now)->tm_mday
                <<  "_"
                <<  std::localtime(&now)->tm_hour
                <<  std::localtime(&now)->tm_min
                <<  std::localtime(&now)->tm_sec 
                << "] ";
}

Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _amount = initial_deposit;
    _totalAmount += _amount;
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" 
              << "amount:" << initial_deposit << ";" 
              << "created" << std::endl;
}

Account::~Account( void ) {
    _nbAccounts--;
    this->_displayTimestamp();
    std::cout << "index:" 
              << _accountIndex << ";" 
              << "amount:" << _amount << ";" 
              << "closed" << std::endl;
}

// -----------------
// PUBLIC METHODS
// -----------------

void    Account::makeDeposit( int deposit ) {
    Account::_displayTimestamp();
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";";
    _amount += deposit;
    std::cout << "deposit:" << deposit << ";"
              << "amount:" << _amount << ";"
              << "nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal ) {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";"
              << "withdrawal:";
    if (withdrawal > this->checkAmount()) {
        std::cout << "refused" << std::endl;
        return false;
    }
    std::cout << withdrawal << ";";
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    std::cout << "amount:" << _amount << ";" << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int     Account::checkAmount( void ) const {
    return (Account::_amount);
}

void    Account::displayStatus( void ) const {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals << std::endl;
}