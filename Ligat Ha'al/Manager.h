#pragma once
#include "Worker.h"
class Manager :public Worker
{
public:
	Manager();
	Manager(const int, const string, const string, const string);
	Manager(const Manager&);
	~Manager();
	float getSalary()const;
	bool isBest()const;
	void setManager();
};