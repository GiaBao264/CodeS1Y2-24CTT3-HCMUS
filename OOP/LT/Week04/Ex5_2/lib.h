#include <iostream>

using namespace std;

class Client {
private:
    string name;
    int id;
public:
    Client(const string&, int);
    void display();
};

class Account {
private:
    Client client;
    string accountNumber;
    double balance;
public:
    Account();
    Account(Client client, string accountNumber, double balance);
    double getBalance();
    Account deposit(double amount);
    Account withdraw(double amount);
    void display();
};

class SavingAccount : public Account {
private:
    double interestRate;
public:
    SavingAccount(Client client, string accountNumber, double balance, double interestRate);
    void applyInterest();
    void display();
};