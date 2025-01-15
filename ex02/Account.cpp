#include <iostream>
#include <iomanip>
#include <sstream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int Account::getTotalAmount( void ) {
    return _totalAmount;
}

int Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void Account::_displayTimestamp( void ) {
    time_t rawtime;
    struct tm *timeinfo;
    std::ostringstream oss;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    oss << "[" 
        << (timeinfo->tm_year + 1900)
        << std::setw(2) << std::setfill('0') << (timeinfo->tm_mon + 1)
        << std::setw(2) << std::setfill('0') << timeinfo->tm_mday
        << "_"
        << std::setw(2) << std::setfill('0') << timeinfo->tm_hour
        << std::setw(2) << std::setfill('0') << timeinfo->tm_min
        << std::setw(2) << std::setfill('0') << timeinfo->tm_sec
        << "]"
        << " ";
    std::cout << oss.str();
}

std::string formatKeyValue(const char *str, int value) {
    std::ostringstream oss;

    oss << str << ":" << value;
    return oss.str();
}

std::string joinWithSemicolon(std::string strings[]) {
    std::ostringstream oss;
    bool first = true;

    for (size_t i = 0; !strings[i].empty(); ++i) {
        if (first)
            first = false;
        else
            oss << ";";
        oss << strings[i];
    }
    return oss.str();
}

void Account::displayStatus() const {
    std::string strings[] = {
        formatKeyValue("index", _accountIndex),
        formatKeyValue("amount", _amount),
        formatKeyValue("deposits", _nbDeposits),
        formatKeyValue("withdrawals", _nbWithdrawals),
    ""};
    _displayTimestamp();
    std::cout << joinWithSemicolon(strings) << std::endl;
}

void Account::makeDeposit(int deposit) {
    int p_amount = _amount;
    _nbDeposits += 1;
    _totalNbDeposits += 1;
    _amount += deposit;
    _totalAmount += deposit;
    std::string strings[] = {
        formatKeyValue("index", _accountIndex),
        formatKeyValue("p_amount", p_amount),
        formatKeyValue("deposit", deposit),
        formatKeyValue("amount", _amount),
        formatKeyValue("nb_deposits", _nbDeposits),
    ""};
    _displayTimestamp();
    std::cout << joinWithSemicolon(strings) << std::endl;
}

void Account::displayAccountsInfos() {
    std::string strings[] = {
        formatKeyValue("accounts", getNbAccounts()),
        formatKeyValue("total", getTotalAmount()),
        formatKeyValue("deposits", getNbDeposits()),
        formatKeyValue("withdrawals", getNbWithdrawals()),
    ""};
    _displayTimestamp();
    std::cout << joinWithSemicolon(strings) << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    std::string withdrawal_str;
    int p_amount;

    p_amount = _amount;
    if (withdrawal > _amount)
        withdrawal_str = "withdrawal:refused";
    else
    {
        _nbWithdrawals += 1;
        _totalNbWithdrawals += 1;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        std::string strings1[] = {
            formatKeyValue("withdrawal", withdrawal),
            formatKeyValue("amount", _amount),
            formatKeyValue("nb_withdrawals", _nbWithdrawals),
        ""};
        withdrawal_str = joinWithSemicolon(strings1);
    }
    std::string strings2[] = {
        formatKeyValue("index", _accountIndex),
        formatKeyValue("p_amount", p_amount),
        withdrawal_str,
    ""};
    _displayTimestamp();
    std::cout << joinWithSemicolon(strings2) << std::endl;
    return true;
}

Account::Account(int amount) {
    _accountIndex = getNbAccounts();
    _amount = amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts += 1;
    _totalAmount += _amount;

    std::string strings[] = {
        formatKeyValue("index", _accountIndex),
        formatKeyValue("amount", _amount),
        "created",
    ""};
    _displayTimestamp();
    std::cout << joinWithSemicolon(strings) << std::endl;
}

Account::~Account() {
    _nbAccounts -= 1;
    _totalAmount -= _amount;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbWithdrawals;

    std::string strings[] = {
        formatKeyValue("index", _accountIndex),
        formatKeyValue("amount", _amount),
        "closed",
    ""};
    _displayTimestamp();
    std::cout << joinWithSemicolon(strings) << std::endl;
}
