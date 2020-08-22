#include "Worker.h"

Worker::Worker() :seniority(0), Person() {}

Worker::Worker(const int seniority, const string fName, const string lName, const string id) : Person(fName, lName, id)
{
	this->seniority = seniority;
}

Worker::Worker(const Worker &worker) : Person(worker)
{
	this->seniority = worker.seniority;
}

void Worker::Print() const
{
	Person::Print();
	cout << "Worker data is:" << endl;
	cout << "Seniority is:" << seniority << endl << endl;
}

void Worker::setWorker()
{
	Person::setPerson();
	cout << "Enter seniority:";
	cin >> seniority;
}

bool Worker::isBest() const
{
	return false;
}



Worker::~Worker() {/*Automatic deallocation*/ }

float Worker::getSalary() const
{
	return BASE;
}

int Worker::getSeniority() const
{
	return seniority;
}
