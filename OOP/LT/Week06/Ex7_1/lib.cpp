#include "lib.h"

Engineer::Engineer(double base, double hours, double rate) {
	baseSalary = base;
	overtimeHours = hours;
	overtimeBonusRate = rate;
}

void Engineer::describeWork() {
	cout << "I design and develop software solutions." << endl;
}

string Engineer::getRole() {
	return "Engineer";
}

double Engineer::getSalary() {
	return baseSalary + (overtimeHours * overtimeBonusRate);
}

Manager::Manager(double base, int size, double rate) {
	baseSalary = base;
	teamSize = size;
	bonusPerMember = rate;
}

void Manager::describeWork() {
	cout << "I manage the team and coordinate projects." << endl;
}

string Manager::getRole() {
	return "Manager";
}

double Manager::getSalary() {
	return baseSalary + (teamSize * bonusPerMember);
}