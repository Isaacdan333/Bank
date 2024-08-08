#include "bank.h"
#include <iostream>
#include <iomanip>

void Bank::createAccount(std::string &name, double deposit) {;
    number++;
    accounts.emplace_back(name, deposit, number);
}

bool Bank::checkAccount(int account_num) {
    if (account_num > number || account_num < 0) {
        return false;
    }
    return true;
}

std::string Bank::getAccount_name(int account_num) {
    return accounts.at(account_num).name;
    
}

double Bank::getBalance(int account_num) {
    return accounts.at(account_num).balance;
}

void Bank::deposit(double deposit, int account_num) {
    accounts.at(account_num).balance += deposit;
}

bool Bank::withdraw(double withdraw, int account_num) {
    if ((accounts.at(account_num).balance - withdraw) < 0 ) {
        return false;
    }
    else {
        accounts.at(account_num).balance -= withdraw;
    }
    return true;
}

bool Bank::transfer(double amount, int account_num_from, int account_num_to) {
    //check if amount is less or equal than account_from_to
    if (amount > accounts.at(account_num_from).balance || amount < 0) {
        std::cout << "Insufficient funds from the person transferring money.\n";
        return false;
    }
    else {
        accounts.at(account_num_from).balance -= amount;
        accounts.at(account_num_to).balance += amount;
    }
    return true;
}

void Bank::ViewAllAccounts() {
    for (auto &account : accounts) {
        std::cout << "Name: " << account.name << " Balance: " << std::fixed << std::setprecision(2) << account.balance << " Account Number: " << account.account_num << std::endl;
    }
}