#include <iostream>
using namespace std;

class BankAccount
{
public:
	float balance;

	BankAccount(): balance(0.0) {}
	BankAccount(float b): balance(b) {}
	BankAccount(BankAccount &other): balance(other.balance) {}
	
	void display(){
	    cout << balance << endl;
	}
	void minus(float n){
	    balance = balance - n;
	}
};

int main() {
	BankAccount A1;
	BankAccount A2(1000);
	BankAccount A3(A2);
	A1.display();
	A3.minus(200);
	A2.display();
	A3.display();
}



