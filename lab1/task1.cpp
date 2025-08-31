#include <iostream>
using namespace std;

class BankAccount {
private:
    string customerName;
    long accountNumber;
    float balance;

public:
    BankAccount() : customerName(""), accountNumber(0), balance(0.0) {}

    BankAccount(string name, long number, float initialBalance) 
        : customerName(name), accountNumber(number), balance(initialBalance) {}

    BankAccount(BankAccount &sourceAccount) 
        : customerName(sourceAccount.customerName), 
          accountNumber(sourceAccount.accountNumber), 
          balance(sourceAccount.balance) {}

    void deductAmount(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Deducted $" << amount << " from account." << endl;
        } else {
            cout << "Error: Insufficient funds!" << endl;
        }
    }

    void displayAccountInfo() {
        cout << "\nCustomer Name: " << customerName << endl 
             << "Account Number: " << accountNumber << endl 
             << "Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount defaultAccount;
    cout << "Default Account:";
    defaultAccount.displayAccountInfo();

    BankAccount customerAccount("Seniya Naeem", 23503, 15000.0);
    cout << "\nCustomer Account:";
    customerAccount.displayAccountInfo();

    BankAccount copiedAccount = customerAccount;
    cout << "\nCopied Account (before deduction):";
    copiedAccount.displayAccountInfo();
    
    cout << "\nDeducting $200 from copied account:";
    copiedAccount.deductAmount(200.0);
    
    cout << "\nCopied Account (after deduction):";
    copiedAccount.displayAccountInfo();
    
    cout << "\nOriginal Customer Account (should be unchanged):";
    customerAccount.displayAccountInfo();

    return 0;
}
