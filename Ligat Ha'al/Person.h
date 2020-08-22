#pragma once
#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
	string fName, lName, id;
public:
	Person();
	Person(const string, const string, const string);
	Person(const Person&);
	virtual ~Person();
	virtual void Print() const;
	virtual bool isBest()const = 0;//pure virtual method
	virtual void setPerson();
	string getID()const;
	virtual string getFName()const;
	virtual string getLName()const;
};
