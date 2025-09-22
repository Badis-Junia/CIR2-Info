#ifndef BANK_HPP
#define BANK_HPP
#include <iostream>

class BankAccount {
    protected:
        int number;
        std::string owner;
        float balance;
    public:
        float deposit(int amount); 
        float withdrawal(int amount); 
};

class CheckingAccount : BankAccount {
    private:
        float overdraftlimit;
    public:
        float withdrawal(float amount);
        
};

class SavingsAccount : BankAccount {
    private:

    public:

};



#endif
