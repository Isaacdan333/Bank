#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>

struct Account {
    std::string name;
    double balance;
    int account_num;

    Account(std::string &name, double balance, int account_num) : name(name), balance(balance), account_num(account_num) {}
};

class Bank{
    public:
    void createAccount(std::string &name, double balance);
    bool checkAccount(int account_num);
    std::string getAccount_name(int account_num);
    double getBalance(int account_num);
    void deposit(double deposit, int account_num);
    bool withdraw(double withdraw, int account_num);
    bool transfer(double amount, int account_num_from, int account_num_to);
    void ViewAllAccounts();

    private:
    std::vector<Account> accounts;
    int number = -1;
    //std::string name;
    //double balance = 0;
};


#endif
