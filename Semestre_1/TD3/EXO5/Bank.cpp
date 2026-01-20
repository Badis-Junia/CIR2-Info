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
