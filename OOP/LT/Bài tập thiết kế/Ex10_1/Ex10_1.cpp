#include <iostream>

using namespace std;

class Goods {
private:
	string name;
	int amount;
	double price;

public:
	Goods(const string& n, int a, double p) : name(n), amount(a), price(p) {};
	string getName() const { return name; }
	int getAmount() const { return amount; }
	double getPrice() const { return price; }
};

class Payable {
public:
	virtual double getPayableAmount() const = 0;
};

class Invoice : public Payable {
private:
	Goods goods;

public:
	Invoice(const Goods& g) : goods(g) {}
	double getPayableAmount() const override { return goods.getAmount() * goods.getPrice(); }
};

class Employee : public Payable {
protected:
	string name;
	string address;

public:
	Employee(const string& n, const string& a) : name(n), address(a) {}
	double getPayableAmount() const override { return 0; }
};

class SalariedEmployee : public Employee {
private:
	double weeklySalary;

public:
	SalariedEmployee(const string& n, const string& a, double salary)
		: Employee(n, a), weeklySalary(salary) {}
	double getPayableAmount() const override { return weeklySalary; }
};

class HourlyEmployee : public Employee {
private:
	double h;
	double hourSalary;

public:
	HourlyEmployee(const string& n, const string& a, double w, double h)
		: Employee(n, a), h(w), hourSalary(h) {}
	double getPayableAmount() const override { return h * hourSalary; }
};

class CommissionEmployee : public Employee {
private:
	double commissionRate;
	double grossSales;

public:
	CommissionEmployee(const string& n, const string& a, double sales, double rate)
		: Employee(n, a), grossSales(sales), commissionRate(rate) {}
	double getPayableAmount() const override { return grossSales * commissionRate; }
};

int main() {
	Invoice invoice(Goods("Laptop", 2, 1500.0));
	SalariedEmployee salariedEmp("Alice", "123 Main St", 800.0);
	HourlyEmployee hourlyEmp("Bob", "456 Oak St", 40, 20.0);
	CommissionEmployee commissionEmp("Charlie", "789 Pine St", 5000.0, 0.1);

	Payable* payables[] = {&invoice, &salariedEmp, &hourlyEmp, &commissionEmp};

	for (const auto& payable : payables) {
		cout << "Payable Amount: $" << payable->getPayableAmount() << endl;
	}

	return 0;
}