#include "lib.h"

int main() {
	vector<Employee*> empList;

	empList.push_back(new Engineer(3000.0, 10.0, 50.0));
	empList.push_back(new Manager(5000.0, 5, 200.0));
	empList.push_back(new Engineer(3200.0, 5.0, 50.0));

	double totalSalary = 0.0;

	cout << "--- Employee Report ---" << endl;

	for (size_t i = 0; i < empList.size(); i++) {
		cout << "Role: " << empList[i]->getRole() << endl;

		cout << "Work: ";
		empList[i]->describeWork();

		double salary = empList[i]->getSalary();
		cout << "Salary: $" << salary << endl;
		cout << "-----------------------" << endl;

		totalSalary += salary;
	}

	cout << "Total Company Salary Payout: " << totalSalary << endl;

	for (Employee* emp : empList) {
		delete emp;
	}
	empList.clear();

	return 0;
}