#include "lib.h"

Client::Client(const string& name, int id) {
    this->name = name;
    this->id = id;
}

void Client::display() {
    cout << "Client Name: " << name << ", ID: " << id << endl;
}

Account::Account() : client("", 0), accountNumber(""), balance(0.0) {}

Account::Account(Client client, string accountNumber, double balance) : client(client) {
    this->client = client;
    this->accountNumber = accountNumber;
    this->balance = balance;
}

double Account::getBalance() {
    return balance;
}

Account Account::deposit(double amount) {
    balance += amount;
    return *this;
}

Account Account::withdraw(double amount) {
    balance -= amount;
    return *this;
}

void Account::display() {
    client.display();
    cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
}

SavingAccount::SavingAccount(Client client, string accountNumber, double balance, double interestRate)
    : Account(client, accountNumber, balance) {
    this->interestRate = interestRate;
}

void SavingAccount::applyInterest() {
    double interest = getBalance() * interestRate / 100;
    deposit(interest);
}

void SavingAccount::display() {
    Account::display();
    cout << "Interest Rate: " << interestRate << endl;
}