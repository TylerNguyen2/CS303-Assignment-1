#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>

using namespace std;



void indexarray(int da[], int len = 0, int n = 0);


void modify(int da[], int n = 0);

int* add(int da[], int len, int n);

void remove(int da[], int n = 0);


//Class that can identify professional and non professional employees
class Employee
{
protected:
	int salary;
public:
	//Function to store employees salery in a public domain
	Employee(int s = 0)
	{
		salary = s;
	}
	//Calculate whether or not salary is monthly or weekly
	virtual int getSalary()
	{
		return salary;
	}
	//Calcualte vacation days earned
	virtual double getVacation()
	{
		return 0;
	}
	//function that calcualtes health insurance
	virtual int getInsurance()
	{
		return 0;
	}
};
//A sub class called professional which makes a new class of employee
class Professional : public Employee
{
	//declared protected variables.
protected:
	double vDays;
	int monthlyHealthCareContribution;

public:
	//professional monthlys salary
	Professional(double d = 0, int c = 0) : Employee(5000)
	{
		vDays = d;
		monthlyHealthCareContribution = c;

	}
	//Determine how much professional employee pays for insurance
	int getInsurance()
	{
		return monthlyHealthCareContribution;
	}
	//How much vacation time for professional employee
	double getVacation()
	{
		double workHours = vDays * 8;
		double profVacaHours = workHours / (40 * 52 - 40);

		return profVacaHours * 40;
	}

};
//A class called Nonprofessional that inherits functions from the Employee class.
class Nonprofessional : public Employee
{
protected:
	int hours;
	double vHours;
	float healthCarePercentage;
public:
	Nonprofessional(int h = 0, float p = 0) : Employee(25 * h)
	{
		hours = h;
		healthCarePercentage = p;
	}
	double getVacation()
	{
		double workHours = hours * 52 - hours;
		double nonProfVacaHours = hours / workHours;
		vHours = nonProfVacaHours * hours;
		return vHours;
	}
	int getInsurance()
	{
		return ((25 * hours) * (healthCarePercentage / 100));
	}
};