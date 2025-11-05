#include "lib.h"

Address::Address() {
    street = "";
    city = "";
    state = "";
}

Address::Address(const string& str, const string& cty, const string& st) {
    street = str;
    city = cty;
    state = st;
}

void Address::display() const {
    cout << street << ", " << city << ", " << state << endl;
}

Student::Student(const string& name, const string& id, const float& gpa, const Address& address) {
    this->name = name;
    this->studentID = id;
    this->gpa = gpa;
    this->address = address;
}

string Student::getGrade() const {
    if(gpa >= 3.5) {
        return "A";
    } else if(gpa >= 2.5) {
        return "B";
    } else if(gpa >= 1.5) {
        return "C";
    } else {
        return "F";
    }
}

void Student::display() const {
    cout << "Name: " << name << ", ID: " << studentID << ", GPA: " << gpa << endl;
    address.display();
}

ExchangeStudent::ExchangeStudent(const string& name, const string& id, const float& gpa, const Address& address, const string& country, int duration) : Student(name, id, gpa, address) {
    homeCountry = country;
    exchangeDuration = duration;
}

void ExchangeStudent::updateDuration(int duration) {
    exchangeDuration = duration;
}

void ExchangeStudent::display() const {
    Student::display();
    cout << "Home Country: " << homeCountry << ", Exchange Duration: " << exchangeDuration << " months" << endl;
}