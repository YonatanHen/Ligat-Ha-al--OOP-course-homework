#pragma once
#include "Person.h"
class Worker :public Person {
protected:
	int seniority;
private:
#define BASE 4500////base salary of worker
public:
	Worker();
	Worker(const int, const string, const string, const string);//seniority,fName,lName,id
	Worker(const Worker&);
	~Worker();
	virtual float getSalary() const;
	virtual int getSeniority()const;
	void Print() const;
	void setWorker();
	bool isBest()const;
};