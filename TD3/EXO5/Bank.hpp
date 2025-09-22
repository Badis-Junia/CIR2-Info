#ifndef BANK_HPP
#define BANK_HPP
#include <iostream>

class BankAccount {
    private:
        int number;
        std::string owner;
        float balance;
    public:
        float deposit(int amount); 
        float withdrawal(int amount); 
};

class CheckingAccount : BankAccount {
    private:

    public:

};

class SavingsAccount : BankAccount {
    private:

    public:

};



#endif
