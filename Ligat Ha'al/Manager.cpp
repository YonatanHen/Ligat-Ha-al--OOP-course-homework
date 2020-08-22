#include "Manager.h"

Manager::Manager() :Worker() {}

Manager::Manager(const int seniority, const string fName, const string lName, const string id) :
	Worker(seniority, fName, lName, id) {}

Manager::Manager(const Manager &manager) : Worker(manager) {}

Manager::~Manager() {/*Automatically deallocation*/ }

float Manager::getSalary() const
{
	return Worker::getSalary() * 3 + seniority * 500;
}

bool Manager::isBest() const
{
	if (seniority > 4) return true;
	return false;
}

void Manager::setManager()
{
	Worker::setWorker();
}
