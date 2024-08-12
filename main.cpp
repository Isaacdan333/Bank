#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include "bank.h"

using namespace std;

void menu() {
    cout << "---------OPTIONS---------\n";
    cout << "1. Create Account.\n";
    cout << "2. View Account.\n";
    cout << "3. Deposit Account.\n";
    cout << "4. Withdraw Account.\n";
    cout << "5. Transfer\n";
    cout << "6. Exit\n";
    cout << "-------------------------\n";
}

bool isInteger(const std::string& input) {
    std::stringstream ss(input);
    int number;
    // try to parse as an integer
    return (ss >> number) && (ss.eof());
}

bool isDouble(const std::string& input) {
    std::stringstream ss(input);
    double number;
    // try to parse as a double
    return (ss >> number) && (ss.eof());
}

int main(int argc, char* args[])
{
    Bank bank;
    
    int choice;
    cout << "Welcome to the banking system.\n" << "What would you like to do first?\n";

    do {
        menu();
        cout << "Enter choice: ";
        cin >> choice;
        cin.clear();
        fflush(stdin);
        switch (choice) {
            case 1: {
                string name;
                string input;
                double deposit;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter initial deposit: ";
                cin >> input;
                if (isDouble(input)) {
                    //convert to double
                    deposit = stod(input);
                    bank.createAccount(name, deposit);
                    cout << "Account created successfully" << endl;
                }
                else {
                    cout << "INVALID NUMBER\n";
                }
                break;

            }
            case 2: {
                int account_number;
                string input;
                cout << "Input Account Number: ";
                cin >> input;
                if (isInteger(input)) {
                    account_number = stoi(input);
                    if (bank.checkAccount(account_number)) {
                        std::cout << std::setw(20) << std::left << "Name"
                        << std::setw(15) << "Balance" 
                        << std::setw(10) << "Account Number" << std::endl;

                        std::cout << std::setw(20) << std::left << bank.getAccount_name(account_number)
                        << std::setw(15) << fixed << setprecision(2) << bank.getBalance(account_number) 
                        << std::setw(10) << bank.getBalance(account_number) << std::endl;
                    }
                    else {
                        cout << "Invalid. Try Again." << endl;
                    }
                }
                else {
                    cout << "INVALID ACCOUNT NUMBER\n";
                }
                break;
            }
            case 3: {
                string input;
                double deposit;
                int account_number;
                cout << "Input Account Number to deposit: ";
                cin >> input;
                if (isInteger(input)) {
                    account_number = stoi(input);
                }
                else {
                    std::cout << "Invalid account number.\n";
                    break;
                }
                if (bank.checkAccount(account_number)) {
                    cout << "Enter amount you want to deposit: ";
                    cin >> input;
                    if (isDouble(input)) {
                        deposit = stod(input);
                    }
                    else {
                        std::cout << "Invalid deposit number.\n";
                        break;
                    }
                    if (deposit > 0) {
                        bank.deposit(deposit, account_number);
                        cout << "Deposit was successful. New balance is: " << fixed << setprecision(2) << bank.getBalance(account_number) << endl;
                    }
                    else {
                        cout << "Insufficient funds." << endl;
                    }
                }
                else {
                    cout << "Invalid. Try Again." << endl;
                }
                
                break;
            }

            case 4: {
                string input;
                double withdraw;
                int account_number;
                cout << "Input Account Number to withdraw from: ";
                cin >> input;
                if (isInteger(input)) {
                    account_number = stoi(input);
                }
                else {
                    std::cout << "Invalid account number.\n";
                    break;
                }
                if (bank.checkAccount(account_number)) {
                    cout << "Enter amount you want to withdraw: ";
                    cin >> input;
                    if (isDouble(input)) {
                    withdraw = stod(input);
                    }
                    else {
                        std::cout << "Invalid withdrawal number\n";
                        break;
                    }
                    if (bank.withdraw(withdraw, account_number)) {
                        cout << "Successfuly withdrawed. New balance is: " << fixed << setprecision(2) << bank.getBalance(account_number) << endl;
                    }
                    else {
                        cout << "Insufficient funds" << endl;
                    }
                }
                else {
                    cout << "Invalid. Try Again." << endl;
                }

                break;
            }
            case 5: {
                string input;
                double transfer_amount;
                int account_num_from, account_num_to;
                cout << "Enter account number you want to transfer from: ";
                cin >> input;
                if (isInteger(input)) {
                    account_num_from = stoi(input);
                }
                else {
                    std::cout << "Invalid account number\n";
                    break;
                }
                cout << "Enter account number you want to transfer to: ";
                cin >> input;
                if (isInteger(input)) {
                    account_num_to = stoi(input);
                }
                else {
                    std::cout << "Invalid account number\n";
                    break;
                }
                if(bank.checkAccount(account_num_from) && bank.checkAccount(account_num_to)) {
                    cout << "Enter amount of money you want to tranfer: ";
                    cin >> input;
                    if (isDouble(input)) {
                        transfer_amount = stod(input);
                    }
                    else {
                        cout << "Invalid transfer number.\n";
                        break;
                    }
                    if (bank.transfer(transfer_amount, account_num_from, account_num_to)) {
                        cout << "Successful transfer from: " << bank.getAccount_name(account_num_from) << " --> " << bank.getAccount_name(account_num_to) << endl;
                    }
                    else {
                        cout << "Invalid." << endl;
                    }
                }
                else {
                    cout << "Invalid Information." << endl;
                }
                break;
            }
            case 6: {
                bank.saveBankInfo();
                cout << "Exiting...";
                break;
            }
            case 7: {
                bank.ViewAllAccounts();
                break;
            }
            default: {
                cout << "Invalid, try agin\n";
                break;
            }
        }
    } while (choice != 6);

    return 0;
}