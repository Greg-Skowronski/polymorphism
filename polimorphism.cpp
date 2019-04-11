// Polimorfia.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class person
{
protected:
	string name;
	int age, weight;
public: 
	void appearance(string text, int years, int kilograms)
	{
		name = text;
		age = years;
		weight = kilograms;
	}
	virtual void personal() = 0;
};

class professor : public person
{
	int wrk_yrs, pbl;
public:
	professor(int wrk, int pb)
	{
		wrk_yrs = wrk;
		pbl = pb;
	}
	virtual void personal()
	{
		cout << name << endl << "Age: " << age << " years old" << endl << "Weight: " << weight << "kg" << endl;
		cout << "Worked years: " << wrk_yrs << endl << "No. of publications: " << pbl << endl;
	}
};

class student : public person
{
	int yr_std;
	string sex;
public:
	student(int yr, string sx)
	{
		yr_std = yr;
		sex = sx;
	}
	virtual void personal()
	{
		cout << name << endl << "Age: " << age << " years old" << endl << "Weight: " << weight << "kg" << endl;
		cout << "Year of study: " << yr_std << endl << "Sex: " << sex << endl;
	}
};

class manager : public person
{
	int salary, contracts;
public:
	manager(int cash, int cntrs)
	{
		salary = cash;
		contracts = cntrs;
	}
	virtual void personal()
	{
		cout << name << endl << "Age: " << age << " years old" << endl << "Weight: " << weight << "kg" << endl;
		cout << "Salary: " << salary << "pln" << endl << "No. of contracts: " << contracts << endl;
	}
};



int main()
{
	person *people[5];

	professor Tadeusiewicz(41,13);
	people[0] = &Tadeusiewicz;
	people[0] ->appearance("Michal", 78, 65);

	professor Krawczyk(27, 2);
	people[1] = &Krawczyk;
	people[1]->appearance("Elzbieta", 52, 59);

	student Skowronski(2, "male");
	people[2] = &Skowronski;
	people[2]->appearance("Grzegorz", 20, 57);

	student Rowinska(1, "female");
	people[3] = &Rowinska;
	people[3]->appearance("Paulina", 19, 51);

	manager Kowalski(4000,3);
	people[4] = &Kowalski;
	people[4]->appearance("Mariusz", 33, 78);

	for (int i = 0; i < 5; i++)
	{
		people[i]->personal();
		cout << endl;
	}

	getchar();
    return 0;
}

