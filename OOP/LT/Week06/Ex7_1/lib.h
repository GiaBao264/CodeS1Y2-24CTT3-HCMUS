#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
public:
	virtual ~Employee() {}

	virtual void describeWork() = 0;
	virtual string getRole() = 0;
	virtual double getSalary() = 0;
};

class Engineer : public Employee {
private:
	double baseSalary;
	double overtimeHours;
	double overtimeBonusRate;

public:
	Engineer(double base, double hours, double rate);
	void describeWork() override;
	string getRole() override;
	double getSalary() override;
};

class Manager : public Employee {
private:
	double baseSalary;
	int teamSize;
	double bonusPerMember;

public:
	Manager(double base, int size, double rate);

	void describeWork() override;
	string getRole() override;
	double getSalary() override;
};
