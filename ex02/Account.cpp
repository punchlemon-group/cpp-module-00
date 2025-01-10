#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "Account.hpp"

#define START_YEAR 1970
#define SECCONDS_IN_A_DAY 86400

void    printTimestamp() {
    // 現在の時刻を取得
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime); // 現在の時刻を取得
    timeinfo = localtime(&rawtime); // ローカルタイムに変換

    // タイムスタンプの形式に合わせて出力
    std::ostringstream oss;
    oss << "[" 
        << (timeinfo->tm_year + 1900)  // 年（1900年を加算）
        << std::setw(2) << std::setfill('0') << (timeinfo->tm_mon + 1)  // 月（1から12）
        << std::setw(2) << std::setfill('0') << timeinfo->tm_mday        // 日
        << "_"
        << std::setw(2) << std::setfill('0') << timeinfo->tm_hour        // 時
        << std::setw(2) << std::setfill('0') << timeinfo->tm_min         // 分
        << std::setw(2) << std::setfill('0') << timeinfo->tm_sec         // 秒
        << "]"
        << " ";

    // 結果を出力
    std::cout << oss.str();
}

void    Account::displayStatus() const {
}

void    Account::makeDeposit(int a) {
}

void    Account::displayAccountsInfos() {
}

bool    Account::makeWithdrawal(int a) {
    return true;
}

Account::Account(int amount) : _amount(amount) {
    static int  index;
    printTimestamp();
    std::cout << "index:" << index << ";" << "amount:" << amount << ";created" << std::endl;
    index++;
}

Account::~Account() {
    static int  index;
    printTimestamp();
    std::cout << "index:" << index << ";" << "amount:" << _amount << ";closed" << std::endl;
    index++;
}
