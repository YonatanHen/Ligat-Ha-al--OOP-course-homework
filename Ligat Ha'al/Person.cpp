#include "Person.h"

Person::Person() :fName(""), lName(""), id("") {}

Person::Person(const string fName, const string lName, const string id)
{
	this->fName = fName;
	this->lName = lName;
	this->id = id;
}

Person::Person(const Person &person)
{
	fName = person.fName;
	lName = person.lName;
	id = person.id;
}

Person::~Person() {/*string deallocte automatically*/ }

void Person::Print() const
{
	cout << "Person data:" << endl;
	cout << "First name:" << fName << endl << "Last Name:" << lName << endl << "ID:" << id << endl;
}

void Person::setPerson()
{
	bool flag = true;
	cout << "Enter first name:";
	cin >> fName;
	cout << "Enter last name:";
	cin >> lName;
	cout << "Enter ID:";
	cin >> id;
}

string Person::getID() const
{
	return id;
}

string Person::getFName() const
{
	return fName;
}

string Person::getLName() const
{
	return lName;
}
