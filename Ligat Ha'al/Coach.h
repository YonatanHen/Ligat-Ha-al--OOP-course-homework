#pragma once
#include "Worker.h"
class Coach :public Worker {
protected:
	string teamName;
	bool IsFormerFootballer;
	int championships;
public:
	Coach();
	Coach(const int, const string, const string, const string, const string, const bool, const int);
	Coach(const Coach&);
	~Coach();
	float getSalary()const;
	bool isBest()const;
	void Print() const;
	bool getIsFormerFootballer() const;
	int getChampionships() const;
	void setCoach(const string);
};