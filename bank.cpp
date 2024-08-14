#include "bank.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

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

int Bank::returnAccountNumber() {
    return number;
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
    std::cout << std::setw(20) << std::left << "Name"
    << std::setw(15) << "Balance" 
    << std::setw(10) << "Account Number" << std::endl;
    for (auto &account : accounts) {
        std::cout << std::setw(20) << std::left << account.name
        << std::setw(15) << std::fixed << std::setprecision(2) << account.balance
        << std::setw(10) << account.account_num << std::endl;   
    }
}

void Bank::saveBankInfo() {
    std::string filename = "Accounts.txt";
    std::ifstream file_check(filename);
    if (file_check) {
        std::cout << "Output file already exists.\n";
    }

    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error with creating file.\n";
    }

    file << std::left << std::setw(20) << "Name"
         << std::setw(15) << "Balance"
         << std::setw(10) << "Account Number\n";

    for (auto &account : accounts) {
        file << std::setw(20) << std::left << account.name
        << std::setw(15) << std::fixed << std::setprecision(2) << account.balance
        << std::setw(10) << account.account_num << std::endl;
    }

    file.close();
}

void Bank::getBankInfo() {
    std::string filename = "Accounts.txt";
    std::string name;
    double amount;
    int account_num;
    std::ifstream file_check(filename);
    if (file_check) {
        std::cout << "Getting Bank information...\n\n";
        // open file for reading
        std::ifstream infile(filename);
        if(!infile) {
            std::cerr << "Error opening the file.\n";
        }

        std::string line;
        std::getline(infile, line); // skipping the header line
        while (std::getline(infile, line)) {
            std::istringstream iss(line);
            std::getline(iss, name, ' ');
            iss >> amount;
            iss >> account_num;
            number++;
            accounts.emplace_back(name, amount, number);
        }

        infile.close();
    }
}