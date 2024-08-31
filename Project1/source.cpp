#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;




class Employee
{
public:
	int id;
	string name;
	double salary;
	int employment_year;
	Employee(int i, string n, double s, int y)
	{
		id = i;
		name = n;
		salary = s;
		employment_year = y;
	}
	Employee()
	{
		id = 0; name = "";
		salary = 0;
		employment_year = 0;
	}
	void updateSalary(double newSalary)
	{
		salary = newSalary;
	}
	void upgrade(double increase)
	{
		if ((2024 - employment_year) >= 10)
			salary += (salary * increase / 100);
	}
};
void main()
{
	unordered_map<int, Employee> employees;

	Employee e1(123, "Mohamed", 3200, 2005);
	Employee e2(234, "Nour", 5600, 2010);
	Employee e3(345, "Meena", 8900, 2008);

	employees[e1.id] = e1;
	employees[e2.id] = e2;
	employees[e3.id] = e3;

	int choice;
	cout << "To Update An Employee: Press 1" << endl << "Upgrade All The Employees: Press 2" << endl;
	cin >> choice;
	switch (choice)
	{

	case 1:
	{
		int ID;
		double Sal;
		cout << "Enter ID and New Salary to Update Employee Salary" << endl;
		cin >> ID >> Sal;
		employees[ID].updateSalary(Sal);
		cout << employees[ID].name << " " << employees[ID].salary;
		break;
	}
	case 2:
		double increaseRate;
		cout << "Enter The Increase Rate" << endl;
		cin >> increaseRate;
		for (auto it = employees.begin();it != employees.end();it++)
		{
			(*it).second.upgrade(10);
			cout << (*it).second.name << " " << (*it).second.salary << endl;
		}
	}
}



