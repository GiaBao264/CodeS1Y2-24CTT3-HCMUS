#include <iostream>
#include <string>

using namespace std;

class Address {
private:
    string street;
    string city;
    string state;
public:
    Address();
    Address(const string& str, const string& cty, const string& st);
    void display() const;
};

class Student {
private:
    string name, studentID;
    float gpa;
    Address address;
public:
    Student(const string& name, const string& id, const float& gpa, const Address& address);
    string getGrade() const;
    void display() const;
};

class ExchangeStudent : public Student {
private:
    string homeCountry;
    int exchangeDuration;
public:
    ExchangeStudent(const string& name, const string& id, const float& gpa, const Address& address, const string& country, int duration);
    void updateDuration(int duration);
    void display() const;
};