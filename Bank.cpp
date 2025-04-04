#include <iostream>
#include <cmath>
using namespace std;

class Bank
{
	public:
		float balance, rate;
	public:
		Bank(float balance, float rate)
		{
			this -> balance = balance;
			this -> rate = rate;
		}
		
		void deposit(float amount)
		{
			balance += amount;
			display();
		}
		
		void withdraw(float amount)
		{
			if(amount > balance)
			{
				cout << "\nInsufficient Balance!\n";
				return;
			}
			balance -= amount;
			display();
		}
		
		void display()
		{
			cout << "\nCurrent Balance: " << balance;
		}
		
		void interest(int time)
		{
			float temp = pow(1 + (rate / 100), time);
			balance *= temp;
			display();
		}
};

int main()
{
	cout << "\nEnter the initial balance and rate of interest: ";
	float bal, rate;
	int n;
	cin >> bal >> rate;
	Bank B(bal, rate);
	while(true)
	{
		cout << "\nEnter \n1. To deposit \n2. To withdraw \n3. To apply compound interest on the current balance: ";
		int ch;
		cin >> ch;
		switch(ch)
		{
			case 1: cout << "\nEnter the amount to deposit: ";
			cin >> bal;
			B.deposit(bal);
			break;
			
			case 2: cout << "\nEnter the amount to withdraw: ";
			cin >> bal;
			B.withdraw(bal);
			break;
			
			case 3: cout << "\nEnter the time span(in years): ";
			cin >> n;
			B.interest(n);
			break;
			
			default: cout << "\nWrong Choice";
			exit(0);
		}
	}
}
